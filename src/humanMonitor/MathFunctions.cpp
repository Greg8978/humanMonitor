#include "humanMonitor/MathFunctions.h"

void MathFunctions::multiplyMatrices4x4(double* result,double* mat1, double* mat2){

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



double MathFunctions::dist3D(tf::Point point1, tf::Point point2){
    return sqrt( pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2) + pow(point1.getZ() - point2.getZ(), 2)  );
}



double MathFunctions::dist2D(tf::Point point1, tf::Point point2){
    return sqrt( pow(point1.getX() - point2.getX(), 2) + pow(point1.getY() - point2.getY(), 2) );
}


bool MathFunctions::isFacing(AgentJoint agentJoint, tf::Point point, double angleThreshold){
  
	double humanAngle = tf::getYaw(agentJoint.orientation);
	//        humanAngle=(humanAngle+3.14)*360/6.28;
	double humanRobotAngle = acos( (fabs(agentJoint.position.getX() - point.getX()))/dist2D(agentJoint.position, point) );
	if (point.getX()<agentJoint.position.getX()) {
	  humanRobotAngle=3.14-humanRobotAngle;
}
	if (point.getY()<agentJoint.position.getY()) {
	  humanRobotAngle=-humanRobotAngle;	
}
        double angleResult = fabs(humanAngle - humanRobotAngle);
	std::cout<<"joint positions\n";
	std::cout<<agentJoint.position.getX()<<"\n";
	std::cout<<agentJoint.position.getY()<<"\n";
	std::cout<<point.getX()<<"\n";
	std::cout<<point.getY()<<"\n";
	std::cout<<"distance\n";
	std::cout<<MathFunctions::dist2D(agentJoint.position,point)<<"\n";
	std::cout<<"angles\n";
	std::cout<<"human angle "<<humanAngle<<"\n";
	std::cout<<"human robot angle "<<humanRobotAngle<<"\n";
	std::cout<<"angle result "<<angleResult<<"\n";
	if( angleResult > angleThreshold ) {
	  return false;
	}
	else { 
	  return true;
	}			
}



