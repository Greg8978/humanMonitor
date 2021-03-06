#include <ros/ros.h>

#include "humanMonitor/HumanReader.h"
#include "tf/transform_listener.h"
#include <math.h>       /* sqrt */
#include "humanMonitor/TRBuffer.h"
#include "opaque-pub.h"
#include "mp-pub.h"


// Robot config
static   std::map<std::string, humanMonitor::niut_JOINT_STR> m_RobotLastConfig;
static   std::map<std::string, humanMonitor::niut_JOINT_STR> m_HumanLastConfig;
static   long m_RobotLastTime;
static   TRBuffer< std::map< std::string, humanMonitor::niut_JOINT_STR > > m_HumanRBuffer(100);
//static   TRBuffer< std::map< std::string, humanMonitor::niut_JOINT_STR > > m_RobotRBuffer(100);

void multiplyMatrices4x4(double* result,double* mat1, double* mat2){

	result[0]     = mat1[0]*mat2[0]     + mat1[1]*(mat2+4)[0]    + mat1[2]*(mat2+8)[0]     + mat1[3]*(mat2+12)[0];
	result[1]     = mat1[0]*mat2[1]     + mat1[1]*(mat2+4)[1]    + mat1[2]*(mat2+8)[1]     + mat1[3]*(mat2+12)[1];
	result[2]     = mat1[0]*mat2[2]     + mat1[1]*(mat2+4)[2]    + mat1[2]*(mat2+8)[2]     + mat1[3]*(mat2+12)[2];
	result[3]     = mat1[0]*mat2[3]     + mat1[1]*(mat2+4)[3]    + mat1[2]*(mat2+8)[3]     + mat1[3]*(mat2+12)[3];
	
	(result+4)[0] = (mat1+4)[0]*mat2[0] + (mat1+4)[1]*(mat2+4)[0] + (mat1+4)[2]*(mat2+8)[0] + (mat1+4)[3]*(mat2+12)[0];
	(result+4)[1] = (mat1+4)[0]*mat2[1] + (mat1+4)[1]*(mat2+4)[1] + (mat1+4)[2]*(mat2+8)[1] + (mat1+4)[3]*(mat2+12)[1];
	(result+4)[2] = (mat1+4)[0]*mat2[2] + (mat1+4)[1]*(mat2+4)[2] + (mat1+4)[2]*(mat2+8)[2] + (mat1+4)[3]*(mat2+12)[2];
	(result+4)[3] = (mat1+4)[0]*mat2[3] + (mat1+4)[1]*(mat2+4)[3] + (mat1+4)[2]*(mat2+8)[3] + (mat1+4)[3]*(mat2+12)[3];
	
	(result+8)[0] = (mat1+8)[0]*mat2[0] + (mat1+8)[1]*(mat2+4)[0] + (mat1+8)[2]*(mat2+8)[0] + (mat1+8)[3]*(mat2+12)[0];
	(result+8)[1] = (mat1+8)[0]*mat2[1] + (mat1+8)[1]*(mat2+4)[1] + (mat1+8)[2]*(mat2+8)[1] + (mat1+8)[3]*(mat2+12)[1];
	(result+8)[2] = (mat1+8)[0]*mat2[2] + (mat1+8)[1]*(mat2+4)[2] + (mat1+8)[2]*(mat2+8)[2] + (mat1+8)[3]*(mat2+12)[2];
	(result+8)[3] = (mat1+8)[0]*mat2[3] + (mat1+8)[1]*(mat2+4)[3] + (mat1+8)[2]*(mat2+8)[3] + (mat1+8)[3]*(mat2+12)[3];
	
	(result+12)[0] = (mat1+12)[0]*mat2[0] + (mat1+12)[1]*(mat2+4)[0] + (mat1+12)[2]*(mat2+8)[0] + (mat1+12)[3]*(mat2+12)[0];
	(result+12)[1] = (mat1+12)[0]*mat2[1] + (mat1+12)[1]*(mat2+4)[1] + (mat1+12)[2]*(mat2+8)[1] + (mat1+12)[3]*(mat2+12)[1];
	(result+12)[2] = (mat1+12)[0]*mat2[2] + (mat1+12)[1]*(mat2+4)[2] + (mat1+12)[2]*(mat2+8)[2] + (mat1+12)[3]*(mat2+12)[2];
	(result+12)[3] = (mat1+12)[0]*mat2[3] + (mat1+12)[1]*(mat2+4)[3] + (mat1+12)[2]*(mat2+8)[3] + (mat1+12)[3]*(mat2+12)[3];


}

void projectJoint(humanMonitor::niut_JOINT_STR joint, double* kinectPos, humanMonitor::niut_JOINT_STR& jointW){

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
	multiplyMatrices4x4(tmp1[0], rotX[0], rotY[0]);
	multiplyMatrices4x4(tmp2[0], rotZ[0], tmp1[0]);
	multiplyMatrices4x4(transformation[0], translation[0], tmp2[0]);
	
	//final transformation

        //         Y  X                  Z  Y
        //         | /                   | /
        // Kinect  |/ ____ Z  ,   World  |/_____X

	jointW.position.x = transformation[0][0]*joint.position.z + transformation[0][1]*joint.position.x + transformation[0][2]*joint.position.y + transformation[0][3];
	jointW.position.y = transformation[1][0]*joint.position.z + transformation[1][1]*joint.position.x + transformation[1][2]*joint.position.y + transformation[1][3];
	jointW.position.z = transformation[2][0]*joint.position.z + transformation[2][1]*joint.position.x + transformation[2][2]*joint.position.y + transformation[2][3];

}

double dist3D(humanMonitor::niut_JOINT_STR joint1, humanMonitor::niut_JOINT_STR joint2){
    return sqrt( pow(joint1.position.x - joint2.position.x, 2) + pow(joint1.position.y - joint2.position.y, 2) + pow(joint1.position.z - joint2.position.z, 2)  );
}


double dist2D(humanMonitor::niut_JOINT_STR joint1, humanMonitor::niut_JOINT_STR joint2){
    return sqrt( pow(joint1.position.x - joint2.position.x, 2) + pow(joint1.position.y - joint2.position.y, 2) );
}



void getPr2JointLocation(tf::TransformListener &listener, std::string joint){
    tf::StampedTransform transform;
    std::string jointId = "/";
    jointId.append(joint);
    try{
        ros::Time now = ros::Time::now();
        listener.waitForTransform("/map", jointId,
                              now, ros::Duration(3.0));
        listener.lookupTransform("/map", jointId,
                              now, transform);
        m_RobotLastTime = now.toNSec();
        m_RobotLastConfig[joint].position.x = transform.getOrigin().x();
        m_RobotLastConfig[joint].position.y = transform.getOrigin().y();
        m_RobotLastConfig[joint].position.z = transform.getOrigin().z();
        // We put these in a ring buffer:
        //m_RobotRBufffer.push_back(m_RobotLastTime, m_RobotLastConfig);

    }    
    catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
    }
}

void updateRobot(tf::TransformListener &listener){
   getPr2JointLocation(listener, "torso_lift_link");
   getPr2JointLocation(listener, "r_gripper_l_finger_link");
   getPr2JointLocation(listener, "l_gripper_l_finger_link");
 }

bool isMoving(TRBuffer< std::map< std::string, humanMonitor::niut_JOINT_STR > > confBuffer, 
        std::string joint, long timelapse, double distanceThreshold, int dimentionality){

    int index;
    double dist = 0.0;
    long actualTimelapse = 0;
    long timeNew = confBuffer.getTimeFromIndex( confBuffer.size() -1 );
    long timeOld = timeNew - timelapse;
    humanMonitor::niut_JOINT_STR jointNew = confBuffer.getDataFromIndex( confBuffer.size() -1 )[joint];


    index = confBuffer.getIndexAfter(timeOld);
    actualTimelapse = timeNew - confBuffer.getTimeFromIndex(index);   // Actual timelapse
    humanMonitor::niut_JOINT_STR jointOld = confBuffer.getDataFromIndex( index )[joint];

    if( dimentionality == 2)
        dist = dist2D(jointOld, jointNew);
    else
        dist = dist3D(jointOld, jointNew); 

    // std::cout << "Distance is " << dist << std::endl;
    //		std::cout << "ds*actualTimeLapse / timelapse " << distanceThreshold * actualTimelapse / timelapse << std::endl;
    //	std::cout << "actual timelapse "<< actualTimelapse << std::endl;
    if( dist < distanceThreshold * actualTimelapse / timelapse) {
	  return false;
	}
	else { 
	  return true;
	}
}

void sendMessageOprs(std::string strMessage) {
  std::string stringMessageBase="(AGENT-STATEMENT PR2_ROBOT HERAKLES_HUMAN1 ";
  std::string completeString="";
  
  char dest[10]="OPRS_DB";
  char message[100];
  
  completeString=stringMessageBase+strMessage+")";
  

  strcpy(message,completeString.c_str());
  //  ROS_INFO("Return message %s",message);
  send_message_string(message,dest);
  
}
int main(int argc, char** argv){

  ros::init(argc, argv, "humanMonitor");


  int mpSocket=external_register_to_the_mp_prot("HumanMonitor", 3300, STRINGS_PT); //oprs stuff
  bool wasMoving=0;
  bool wasMovingRightHand=0;
  bool wasMovingLeftHand=0;
  bool wasPresent=0;
  bool wasFar=0;
  bool wasClose=0;
  bool wasTooClose=0;
  bool wasCloseToRightGripper=0;
  bool wasCloseToLeftGripper=0;

  std::string stringMessageComplete;

  ros::NodeHandle node;

  HumanReader humanRd(node);
  double far = 2.5;
  double close = 1.3;
  double distBodies = 0.0;
  double distLHandToGripper = 0.0;
  double distRHandToGripper = 0.0;


  tf::TransformListener listener;
  int niut_TORSO = 3;
  int niut_LEFT_HAND = 9;
  int niut_RIGHT_HAND = 15;
  std::string humanTorso = "torso";
  std::string humanLHand = "l_hand";
  std::string humanRHand = "r_hand";

  std::string robotTorso = "torso_lift_link";
  std::string robotLGripper = "l_gripper_l_finger_link";
  std::string robotRGripper = "r_gripper_l_finger_link";
  humanMonitor::niut_JOINT_STR rHandJoint;
  humanMonitor::niut_JOINT_STR lHandJoint;
  humanMonitor::niut_JOINT_STR torsoJoint;
  humanMonitor::niut_JOINT_STR rHandJointW;
  humanMonitor::niut_JOINT_STR lHandJointW;
  humanMonitor::niut_JOINT_STR torsoJointW;
  double kinectPos[6];
  //TODO: Move this in a service
  kinectPos[0] = 7.25;
  kinectPos[1] = 6.55;
  kinectPos[2] = 2.2;
  kinectPos[3] = 0;
  kinectPos[4] = 0.84;
  kinectPos[5] = -1.57;



  while( node.ok() ){
    ros::spinOnce();

    // For now we focus on human with trackedId = 0.
    if(humanRd.isPresent()){
      if (wasPresent==0) {
	std::cout << "[Fact] Human is present!" << std::endl;
	sendMessageOprs("isPresent TRUE"); 
	wasPresent=1;
      }

      //Get Human joints in kinect frame
      rHandJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_RIGHT_HAND];
      lHandJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_LEFT_HAND];
      torsoJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_TORSO];


      //Get joints in same frame
      if(rHandJoint.position.x != 0.0){
        projectJoint(rHandJoint, kinectPos, rHandJointW);
        m_HumanLastConfig[humanRHand] = rHandJointW;
      }
      if(lHandJoint.position.x != 0.0){
        projectJoint(lHandJoint, kinectPos, lHandJointW);
        m_HumanLastConfig[humanLHand] = lHandJointW;
      }
      if(torsoJoint.position.x != 0.0){
        projectJoint(torsoJoint, kinectPos, torsoJointW);
        m_HumanLastConfig[humanTorso] = torsoJointW;
      }
      m_HumanRBuffer.push_back(humanRd.m_LastTime, m_HumanLastConfig);

      //Compute human motion:
      long timeThreshold = pow(10,9);               // 1sec
      double distanceThreshold = 0.2;               // 10 cms
      if( (isMoving(m_HumanRBuffer, humanTorso, timeThreshold, distanceThreshold, 2)) ){
	if (wasMoving==0){
	  std::cout << "[Fact] Human is moving!" << std::endl;
	  sendMessageOprs("isMoving TRUE");
	  wasMoving=1;
	}
	if(wasMovingRightHand==0) {
	  sendMessageOprs("isMovingRightHand TRUE");
	  wasMovingRightHand=1;
	}
	if(wasMovingLeftHand==0) {
	  sendMessageOprs("isMovingLeftHand TRUE");
	  wasMovingLeftHand=1;
	}
      }
      else
	{
	  if(wasMoving==1) {
	    std::cout << "[Fact] Human is not moving!" << std::endl;
	    sendMessageOprs("isMoving FALSE");
	    wasMoving=0;
	  }
	  if((isMoving(m_HumanRBuffer, humanRHand, timeThreshold, distanceThreshold*4/3, 3)) && (wasMovingRightHand==0)){
	    wasMovingRightHand=1;
	    sendMessageOprs("isMovingRightHand TRUE");
	    std::cout << "[Fact] Human right hand is moving" << std::endl;
	    
	  }
	  else if(wasMovingRightHand==1) {
	    wasMovingRightHand=0;
	    sendMessageOprs("isMovingRightHand FALSE");
	  }
	  if( (isMoving(m_HumanRBuffer, humanLHand, timeThreshold, distanceThreshold*4/3, 3)) && (wasMovingLeftHand==0 )){
	    wasMovingLeftHand=1;
	    sendMessageOprs("isMovingLeftHand  TRUE");
	    std::cout << "[Fact] Human left hand is moving" << std::endl;
	  }
	  else if (wasMovingLeftHand==1) {
	    wasMovingLeftHand=0;
	    sendMessageOprs("isMovingLeftHand FALSE");
	  }
	}
      
	  



      updateRobot(listener);


      //Compute relative distances (human / robot):
      //std::cout << "Human Torso x: " << torsoJointW.position.x << "y: " << torsoJointW.position.y << std::endl;
      // std::cout << "Robot Torso x: " << m_RobotLastConfig[robotTorso].position.x << "y: " <<  m_RobotLastConfig[robotTorso].position.y << std::endl;

      if(torsoJoint.position.x != 0.0){
        distBodies = dist2D(torsoJointW, m_RobotLastConfig[robotTorso]);
	 std::cout << "Dist human robot: " << distBodies << std::endl;

	 if( (distBodies > far) ){
	  if (wasFar==0) {
	    std::cout << "[Fact] Human is far" << std::endl;
	    sendMessageOprs("distance FAR");
	    wasFar=1;
	    wasTooClose=0;
	    wasClose=0;
	  }
	}else if((distBodies > close)){
	   if (wasClose==0) {
	     std::cout << "[Fact] Human is near" << std::endl;
	     wasFar=0;
	     wasTooClose=0;
	     wasClose=1;
	     sendMessageOprs("distance CLOSE");
	   }
	  //We compute the hand to gripper distance in NEAR case.
	  //Left gripper
	  distLHandToGripper = dist3D(lHandJointW, m_RobotLastConfig[robotLGripper]);
	  distRHandToGripper = dist3D(rHandJointW, m_RobotLastConfig[robotLGripper]);
	  if( ((distLHandToGripper < 0.5) || (distRHandToGripper < 0.5)) && wasCloseToLeftGripper==0) {
	    wasCloseToLeftGripper=1;
	    sendMessageOprs("handCloseToLeftGripper TRUE");
	    std::cout << "[Fact] Danger! Human hand is close to left gripper!" << std::endl;
	  }
	  else if (wasCloseToLeftGripper==1) {
	    wasCloseToLeftGripper=0;
	    sendMessageOprs("handCloseToLeftGripper FALSE");
	  }

	  //Right gripper
	  distLHandToGripper = dist3D(lHandJointW, m_RobotLastConfig[robotRGripper]);
	  distRHandToGripper = dist3D(rHandJointW, m_RobotLastConfig[robotRGripper]);
	  if( ((distLHandToGripper < 0.5) || (distRHandToGripper < 0.5)) && wasCloseToRightGripper==0){
	    wasCloseToRightGripper=1;
	    sendMessageOprs("handCloseToRightGripper TRUE");
	    std::cout << "[Fact] Danger! Human hand is close to right gripper!" << std::endl;
	  }
	  else if (wasCloseToRightGripper==1) {
	    wasCloseToRightGripper=0;
	    sendMessageOprs("handCloseToRightGripper FALSE");
	  }

	}else if (wasTooClose==0) {
	  sendMessageOprs("distance DANGER");
	  wasTooClose=1;
	  std::cout << "[Fact] Human is too close!" << std::endl;
	}
      }else {
	std::cout << "Human Torso not available " << std::endl;
      }
    } else if (wasPresent==1) {
      wasPresent=0;
      sendMessageOprs("isPresent FALSE");
      std::cout << "[Fact] Human is not present" << std::endl;
    }
  }
}
