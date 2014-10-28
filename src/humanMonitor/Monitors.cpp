#include "humanMonitor/Monitors.h"
#include "humanMonitor/OprsBridge.h"


Monitors::Monitors() {
    far=2.5;
    close=1.3;
    distLHandToGripper=0.7;
    distRHandToGripper=0.7;
    distHandExtended=0.7;
}

bool Monitors::computeOrientationToRobot(Agent m_agentsLastConfig, Agent m_robotLastConfig, string joint) {

    return MathFunctions::isFacing(m_agentsLastConfig.joints[joint], m_robotLastConfig.joints[TORSO].position, 0.5);
}

map<string,bool> Monitors::computeHandDistance(Agent m_agentsLastConfig, Agent m_robotLastConfig) {

    map<string,bool> result;
    AgentJoint robotLGripperJoint=m_robotLastConfig.joints[RIGHT_HAND];
    AgentJoint robotRGripperJoint=m_robotLastConfig.joints[LEFT_HAND];

    AgentJoint lHandJoint=m_agentsLastConfig.joints[LEFT_HAND];
    AgentJoint rHandJoint=m_agentsLastConfig.joints[RIGHT_HAND];
    
    //Left gripper
    distLHandToGripper = MathFunctions::dist3D(lHandJoint.position, robotLGripperJoint.position);
    distRHandToGripper = MathFunctions::dist3D(rHandJoint.position, robotLGripperJoint.position);
    if( ((distLHandToGripper < 0.5) || (distRHandToGripper < 0.5))) {
	result["LEFT"]=true;
    }
    else {
	result["LEFT"]=false;
    }

    //Right gripper
    distLHandToGripper = MathFunctions::dist3D(lHandJoint.position, robotRGripperJoint.position);
    distRHandToGripper = MathFunctions::dist3D(rHandJoint.position, robotRGripperJoint.position);
    if( ((distLHandToGripper < 0.6) || (distRHandToGripper < 0.6))){
	result["RIGHT"]=true;
    }
    else  {
	result["RIGHT"]=false;

    }
    return result;
}


string Monitors::computeDistance(Agent m_agentsLastConfig, Agent m_robotLastConfig, string joint) {
    string result;
    
    tf::Point robotTorso= m_robotLastConfig.joints[TORSO].position;
  
    tf::Point agentTorso= m_agentsLastConfig.joints[joint].position;
	
    if(agentTorso.getX() != 0.0){
	    double distBodies = MathFunctions::dist2D(agentTorso, robotTorso);
	    //	 std::cout << "Dist human robot: " << distBodies << std::endl;

	    if( (distBodies > far) ){
		result="FAR";
		}
	    else if((distBodies > close)){
		result="CLOSE";
	    }else {
		result="DANGER";
	    }
	    
	}else {
	    result="UNKNOWN";
	    std::cout << "Human Torso not available " << std::endl;
	}
	return result;
}

string Monitors::computeAgentPose(Agent m_agentsLastConfig) {
    string result;

    //We compute the distance from the hand of the human to its body
    double distHand = MathFunctions::dist3D(m_agentsLastConfig.joints[RIGHT_HIP].position,m_agentsLastConfig.joints[RIGHT_HAND].position);
    if(distHand>distHandExtended) {
	result="EXTENDED";
	
    }	else {
	    result="CLOSE";
    }

    return result;
}

bool Monitors::computeMotion(TRBuffer< Agent >  confBuffer, string joint) {
    long timelapse = pow(10,9);               // 1sec
    double distanceThreshold = 0.2;               // 10 cms
    int dimensionality=2;
    


    
    int index;
    double dist = 0.0;
    long actualTimelapse = 0;
    long timeNew = confBuffer.getTimeFromIndex( confBuffer.size() -1 );
    long timeOld = timeNew - timelapse;
    AgentJoint jointNew = confBuffer.getDataFromIndex( confBuffer.size() -1 ).joints[joint];


    index = confBuffer.getIndexAfter(timeOld);
    actualTimelapse = timeNew - confBuffer.getTimeFromIndex(index);   // Actual timelapse
    AgentJoint jointOld = confBuffer.getDataFromIndex( index ).joints[joint];
    
    if( dimensionality == 2)
        dist = MathFunctions::dist2D(jointOld.position, jointNew.position);
    else
        dist = MathFunctions::dist3D(jointOld.position, jointNew.position); 

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
