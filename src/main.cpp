#include <ros/ros.h>

#include "humanMonitor/HumanReader.h"
#include "tf/transform_listener.h"
#include <math.h>       /* sqrt */

   // Robot config
static   std::map<std::string, humanMonitor::niut_JOINT_STR> m_LastConfig;
static   uint64_t m_LastTime;

void multiplyMatrices4x4(float* result,float* mat1, float* mat2){

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

void projectJoint(humanMonitor::niut_JOINT_STR joint, float* kinectPos, humanMonitor::niut_JOINT_STR jointW){

	float translation[4][4], rotX[4][4], rotY[4][4], rotZ[4][4], transformation[4][4], tmp1[4][4], tmp2[4][4];

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

float dist3D(humanMonitor::niut_JOINT_STR joint1, humanMonitor::niut_JOINT_STR joint2){
    return sqrt( pow(joint1.position.x - joint2.position.x, 2) + pow(joint1.position.y - joint2.position.y, 2) + pow(joint1.position.z - joint2.position.z, 2)  );
}


float dist2D(humanMonitor::niut_JOINT_STR joint1, humanMonitor::niut_JOINT_STR joint2){
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
        m_LastTime = now.toNSec();
        m_LastConfig[joint].position.x = transform.getOrigin().x();
        m_LastConfig[joint].position.y = transform.getOrigin().y();
        m_LastConfig[joint].position.z = transform.getOrigin().z();

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


int main(int argc, char** argv){

  ros::init(argc, argv, "humanMonitor");
  ros::NodeHandle node;

  HumanReader humanRd(node);
  float far = 3.0;
  float close = 1.0;
  float distBodies = 0.0;
  float distLHandToGripper = 0.0;
  float distRHandToGripper = 0.0;


  tf::TransformListener listener;
  int niut_TORSO = 3;
  int niut_LEFT_HAND = 9;
  int niut_RIGHT_HAND = 15;
  std::string robotTorso = "torso_lift_link";
  std::string robotLGripper = "l_gripper_l_finger_link";
  std::string robotRGripper = "r_gripper_l_finger_link";
  humanMonitor::niut_JOINT_STR rHandJoint;
  humanMonitor::niut_JOINT_STR lHandJoint;
  humanMonitor::niut_JOINT_STR torsoJoint;
  humanMonitor::niut_JOINT_STR rHandJointW;
  humanMonitor::niut_JOINT_STR lHandJointW;
  humanMonitor::niut_JOINT_STR torsoJointW;
  float kinectPos[6];
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
      //Get Human joints in kinect frame
      rHandJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_RIGHT_HAND];
      lHandJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_LEFT_HAND];
      torsoJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_TORSO];

      //Get joints in same frame
      projectJoint(rHandJoint, kinectPos, rHandJointW);
      projectJoint(lHandJoint, kinectPos, lHandJointW); 
      projectJoint(torsoJoint, kinectPos, torsoJointW); 
      updateRobot(listener);


      //Compute relative distances (human / robot):
      distBodies = dist2D(torsoJointW, m_LastConfig[robotTorso]);
      if( distBodies > far ){
        std::cout << "[Fact] Human is far" << std::endl;

      }else if(distBodies > close){
        std::cout << "[Fact] Human is near" << std::endl;

        //We compute the hand to gripper distance in NEAR case.
        //Left gripper:
        distLHandToGripper = dist3D(lHandJointW, m_LastConfig[robotLGripper]);
        distRHandToGripper = dist3D(rHandJointW, m_LastConfig[robotLGripper]);
        if( (distLHandToGripper < 0.5) || (distRHandToGripper < 0.5)){
          std::cout << "[Fact] Danger! Human hand is close to left gripper!" << std::endl;
        }

        //Right gripper
        distLHandToGripper = dist3D(lHandJointW, m_LastConfig[robotRGripper]);
        distRHandToGripper = dist3D(rHandJointW, m_LastConfig[robotRGripper]);
        if( (distLHandToGripper < 0.5) || (distRHandToGripper < 0.5)){
           std::cout << "[Fact] Danger! Human hand is close to right gripper!" << std::endl;
        }

      }else{
        std::cout << "[Fact] Human is too close!" << std::endl;
      }
    }
  }
}
