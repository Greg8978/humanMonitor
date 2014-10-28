// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.

#include "humanMonitor/HumanReaderKinect.h"



#define HumanReader_DEBUG 0



HumanReaderKinect::HumanReaderKinect(ros::NodeHandle& node, double * kinectPos): node_(node), kinectPos_(kinectPos)  {
    std::cout << "Initializing HumanReader" << std::endl;
    // ******************************************
    // Starts listening to the joint_states topic
    // ******************************************
	
    sub_ = node_.subscribe("/niut/Human", 1, &HumanReaderKinect::humanJointCallBack, this);
    m_LastTime = 0;

   
}
        
void HumanReaderKinect::humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg){
    vector<int> trackedJoints;
    trackedJoints.push_back(0);
    trackedJoints.push_back(3);
    trackedJoints.push_back(9);
    trackedJoints.push_back(15);
    trackedJoints.push_back(22);


    map<int,string> niutToString;
    niutToString[3]=TORSO;
    niutToString[9]=LEFT_HAND;
    niutToString[15]=RIGHT_HIP;
    niutToString[0]=HEAD;

    //msg->filtered_users[i];
    for(int i=0; i<16; i++){
	if( msg->filtered_users[i].trackedId > -1 && msg->filtered_users[i].date.t_sec != 0){

	    for (int j=0; j<trackedJoints.size(); j++) {
		double x,y,z;
		
		int niutJoint=trackedJoints[j];
		
		x=msg->filtered_users[i].skeleton.joint[niutJoint].position.x;
		y=msg->filtered_users[i].skeleton.joint[niutJoint].position.y;
		z=msg->filtered_users[i].skeleton.joint[niutJoint].position.z;
		AgentJoint joint,jointW;
		joint.position.setX(x);
		joint.position.setY(y);
		joint.position.setZ(z);
		projectJoint(joint,kinectPos_,jointW);
		
		string jointString=niutToString[trackedJoints[j]];
		m_LastConfig[msg->filtered_users[i].trackedId].joints[jointString]=jointW;;
	    }


	    m_LastTime = msg->filtered_users[i].date.t_sec * pow(10,9) + 
		msg->filtered_users[i].date.t_usec;
	    //        std::cout << "time from callback " << m_LastTime << std::endl;
	    if(HumanReader_DEBUG){
		std::cout << "user's trackedId" << msg->filtered_users[i].trackedId << std::endl;
	    }
	}
    }
    if(HumanReader_DEBUG){
	std::cout << std::endl;
    }

}

void HumanReaderKinect::projectJoint(AgentJoint joint, double* kinectPos, AgentJoint& jointW){

    double translation[4][4], rotX[4][4], rotY[4][4], rotZ[4][4], transformation[4][4], tmp1[4][4], tmp2[4][4];

	//translation transformation matrice
	translation[0][0] = 1;
	translation[0][1] = 0;
	translation[0][2] = 0;
	translation[0][3] = kinectPos[0];
	
	translation[1][0] = 0;
	translation[1][1] = 1;
	translation[1][2] = 0;
	translation[1][3] = kinectPos[1];
	
	translation[2][0] = 0;
	translation[2][1] = 0;
	translation[2][2] = 1;
	translation[2][3] = kinectPos[2];
	
	translation[3][0] = 0;
	translation[3][1] = 0;
	translation[3][2] = 0;
	translation[3][3] = 1;
	
	//rotation in x axe transformation matrice
	rotX[0][0] = 1;
	rotX[0][1] = 0;
	rotX[0][2] = 0;
	rotX[0][3] = 0;
	
	rotX[1][0] = 0;
	rotX[1][1] = cos(kinectPos[3]);
	rotX[1][2] = -sin(kinectPos[3]);
	rotX[1][3] = 0;
	
	rotX[2][0] = 0;
	rotX[2][1] = sin(kinectPos[3]);
	rotX[2][2] = cos(kinectPos[3]);
	rotX[2][3] = 0;
	
	rotX[3][0] = 0;
	rotX[3][1] = 0;
	rotX[3][2] = 0;
	rotX[3][3] = 1;
	
	//rotation in y axe transformation matrice
	rotY[0][0] = cos(kinectPos[4]);
	rotY[0][1] = 0;
	rotY[0][2] = sin(kinectPos[4]);
	rotY[0][3] = 0;
	
	rotY[1][0] = 0;
	rotY[1][1] = 1;
	rotY[1][2] = 0;
	rotY[1][3] = 0;
	
	rotY[2][0] = -sin(kinectPos[4]);
	rotY[2][1] = 0;
	rotY[2][2] = cos(kinectPos[4]);
	rotY[2][3] = 0;
	
	rotY[3][0] = 0;
	rotY[3][1] = 0;
	rotY[3][2] = 0;
	rotY[3][3] = 1;
	
	//rotation in z axe transformation matrice
	rotZ[0][0] = cos(kinectPos[5]);
	rotZ[0][1] = -sin(kinectPos[5]);
	rotZ[0][2] = 0;
	rotZ[0][3] = 0;
	
	rotZ[1][0] = sin(kinectPos[5]);
	rotZ[1][1] = cos(kinectPos[5]);
	rotZ[1][2] = 0;
	rotZ[1][3] = 0;
	
	rotZ[2][0] = 0;
	rotZ[2][1] = 0;
	rotZ[2][2] = 1;
	rotZ[2][3] = 0;
	
	rotZ[3][0] = 0;
	rotZ[3][1] = 0;
	rotZ[3][2] = 0;
	rotZ[3][3] = 1;
	
	//transformation matrice = translation*rotX*rotY*rotZ
	MathFunctions::multiplyMatrices4x4(tmp1[0], rotX[0], rotY[0]);
	MathFunctions::multiplyMatrices4x4(tmp2[0], rotZ[0], tmp1[0]);
	MathFunctions::multiplyMatrices4x4(transformation[0], translation[0], tmp2[0]);
	
	//final transformation

        //         Y  X                  Z  Y
        //         | /                   | /
        // Kinect  |/ ____ Z  ,   World  |/_____X

	jointW.position.setX(transformation[0][0]*joint.position.getZ() + transformation[0][1]*joint.position.getX() + transformation[0][2]*joint.position.getY() + transformation[0][3]);
	jointW.position.setY(transformation[1][0]*joint.position.getZ() + transformation[1][1]*joint.position.getX() + transformation[1][2]*joint.position.getY() + transformation[1][3]);
	jointW.position.setZ(transformation[2][0]*joint.position.getZ() + transformation[2][1]*joint.position.getX() + transformation[2][2]*joint.position.getY() + transformation[2][3]);

}




     

bool HumanReaderKinect::isPresent(int i){
  timeval curTime;
  gettimeofday(&curTime, NULL);
  unsigned long now = curTime.tv_sec * pow(10,9) + curTime.tv_usec;
  unsigned long timeThreshold = pow(10,9);
  //std::cout << "current time: " << now <<  "  human time: " << m_LastTime << std::endl;
  long timeDif = m_LastTime - now;
  //std::cout << "time dif: " << timeDif << std::endl;

  if ( fabs(timeDif) < timeThreshold)
      return true;
  else
      return false;
}
