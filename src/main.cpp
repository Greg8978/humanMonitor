#include <ros/ros.h>

#include "humanMonitor/HumanReader.h"
#include "humanMonitor/RobotReader.h"




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

void projectJoint(humanMonitor::niut_JOINT_STR joint, float* kinectPos, float* jointTranspos){

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
	multiplyMatrices4x4(tmp1[0], rotY[0], rotZ[0]);
	multiplyMatrices4x4(tmp2[0], rotX[0], tmp1[0]);
	multiplyMatrices4x4(transformation[0], translation[0], tmp2[0]);
	
	//final transformation

        //         Y  X                  Z  Y
        //         | /                   | /
        // Kinect  |/ ____ Z  ,   World  |/_____X

	jointTranspos[0] = transformation[0][0]*joint.position.z + transformation[0][1]*joint.position.x + transformation[0][2]*joint.position.y + transformation[0][3];
	jointTranspos[1] = transformation[1][0]*joint.position.z + transformation[1][1]*joint.position.x + transformation[1][2]*joint.position.y + transformation[1][3];
	jointTranspos[2] = transformation[2][0]*joint.position.z + transformation[2][1]*joint.position.x + transformation[2][2]*joint.position.y + transformation[2][3];

}

int main(int argc, char** argv){

  ros::init(argc, argv, "humanMonitor");
  ros::NodeHandle node;

  std::cout << "Initializing HumanReader " << std:: endl;
  HumanReader humanRd(node);
  RobotReader robotRd(node);

  int niut_RIGHT_HAND = 15;
  humanMonitor::niut_JOINT_STR testJoint;
  //testJoint.position.x = -6.55;
  //testJoint.position.y = -2.2;
  //testJoint.position.z = -6.25;
  float testTranspos[3], kinectPos[6];
  kinectPos[0] = 7.25;
  kinectPos[1] = 6.55;
  kinectPos[2] = 2.2;
  kinectPos[3] = 0;
  kinectPos[4] = 0.84;
  kinectPos[5] = -1.57;


  while( node.ok() ){
    testJoint = humanRd.m_LastConfig[0].skeleton.joint[niut_RIGHT_HAND];

    projectJoint(testJoint, kinectPos, testTranspos);


    //std::cout << "Hand position : x :" << testTranspos[0] << " y : " << testTranspos[1] << " z : " << testTranspos[2] << std::endl;
  }

  //while( node.ok() ){
  // std::cout << "Last human time received " << humanRd.m_LastTime << std::endl;
  // std::cout << "number of human received " << humanRd.m_LastConfig.size() << std::endl;




   //std::cout << "Last robot time received " << robotRd.m_LastTime << std::endl;
  // std::cout << "number of robot joint received " << robotRd.m_LastConfig.size() << std::endl;
  //}

}
