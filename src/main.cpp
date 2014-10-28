
#include <ros/ros.h>
#include "humanMonitor/HumanReaderRos.h"
#include "humanMonitor/HumanReaderKinect.h"
#include "tf/transform_listener.h"
#include <math.h>       /* sqrt */
#include "humanMonitor/TRBuffer.h"
#include "humanMonitor/Human.h"
#include "humanMonitor/MathFunctions.h"
#include "humanMonitor/Agent.h"
#include "humanMonitor/OprsBridge.h"
#include "humanMonitor/Monitors.h"
#include <sstream>

// Agent config
static Agent  m_RobotLastConfig;
static  map<int,Agent> m_HumanLastConfig;   //Miki: switched from map to the Human structure
static  long m_RobotLastTime;
static  map<int, TRBuffer< Agent > > m_HumanRBuffer;
std::string robotTorso = "torso_lift_link";
std::string robotLGripper = "l_gripper_l_finger_link";
std::string robotRGripper = "r_gripper_l_finger_link";
static std::string robot="SPENCER_ROBOT";  //possible values PR2, SPENCER  

//static   TRBuffer< std::map< std::string, humanMonitor::niut_JOINT_STRx > > m_RobotRBuffer(100);

//tracking information
static bool trackHead=true;
static bool trackRightHand=false;
static bool trackLeftHand=false;
static bool trackRightHip=false;
static bool trackTorso=false;

//system uses
static bool USE_KINECT=false;
static bool USE_ROS=true;


//ros config
static string topic="/optitrack_person/tracked_persons";



void getRobotJointLocation(tf::TransformListener &listener, std::string joint){
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
        m_RobotLastConfig.joints[joint].position.setX(transform.getOrigin().x());
        m_RobotLastConfig.joints[joint].position.setY(transform.getOrigin().y());
	m_RobotLastConfig.joints[joint].position.setZ(transform.getOrigin().z());
        // We put these in a ring buffer:
        //m_RobotRBufffer.push_back(m_RobotLastTime, m_RobotLastConfig);

    }    
    catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
    }
}



void updateRobot(tf::TransformListener &listener){
    if(robot=="PR2_ROBOT") {
	getRobotJointLocation(listener, "torso_lift_link");
	getRobotJointLocation(listener, "r_gripper_l_finger_link");
	getRobotJointLocation(listener, "l_gripper_l_finger_link");
    }
    else if(robot=="SPENCER_ROBOT") {
	getRobotJointLocation(listener, "torso_lift_link");
    
    }

}







int main(int argc, char** argv){
  OprsBridge oprsBridge(robot);    

    //monitor variables
    Monitors monitors;

    map<int,bool> wasMoving;
    map<int,bool> wasMovingRightHand;
    map<int,bool> wasMovingLeftHand;
    map<int,bool>  wasPresent;
    map<int, map <string,bool> >  previousHandDistances;

    map<int,string> previousFacing;
    map<int,string> previousDistance;
    map<int,string> previousPose;
    int closestAgent=-10;


    
    //ros stuff
    ros::init(argc, argv, "humanMonitor");
    ros::NodeHandle node;

    //human reader is the object that gets human data. Can be HumanReaderRos or HumanReaderKinect. Should be generalized with a parameter at the start and a superclass of the various possible readers
    HumanReaderRos humanRd(node, trackHead, trackRightHand, topic);


    

	tf::TransformListener listener;



	AgentJoint rHandJoint;
	AgentJoint lHandJoint;
	AgentJoint torsoJoint;
	AgentJoint rHipJoint;
	AgentJoint headJoint;
	AgentJoint rHandJointW;
	AgentJoint lHandJointW;
	AgentJoint torsoJointW;
	AgentJoint rHipJointW;

	double kinectPos[6];
	//TODO: Move this in a service
	kinectPos[0] = 7.25;
	kinectPos[1] = 6.55;
	kinectPos[2] = 2.2;
	kinectPos[3] = 0;
	kinectPos[4] = 0.84;
	kinectPos[5] = -1.57;


	oprsBridge.connect("HumanMonitor");

	while( node.ok() ){
	    ros::spinOnce();

	    double minDistance=1000;
	    double minAgent=-10;
	    updateRobot(listener);
	    //	    ROS_INFO("Updated Robot");
	    //ROS_INFO("Number of Agents: %d",humanRd.m_LastConfig.size());
	    for(map<int,Agent>::iterator currentAgent=humanRd.m_LastConfig.begin(); currentAgent!=humanRd.m_LastConfig.end(); currentAgent++) {


		int i=currentAgent->first;
		bool isPresent=humanRd.isPresent(i);
		if (isPresent!=wasPresent[i]) {
		  cout<<"Agent "<<i<<" isPresent "<<isPresent<<"\n";
		    oprsBridge.updateSupervisor("isPresent", i, isPresent, wasPresent[i]);
		    wasPresent[i]=isPresent;
		}
		if (isPresent) {
		
		    //Get Human joints in kinect frame
		  
		    if (trackHead) {
			m_HumanLastConfig[i].joints[HEAD]=currentAgent->second.joints[HEAD];
		    }
		    else if (trackRightHand) {
			m_HumanLastConfig[i].joints[RIGHT_HAND]=currentAgent->second.joints[RIGHT_HAND];
		    }
		    else if (trackLeftHand) {
			m_HumanLastConfig[i].joints[LEFT_HAND]=currentAgent->second.joints[LEFT_HAND];
		    }
		    else if (trackTorso) {
			m_HumanLastConfig[i].joints[TORSO]=currentAgent->second.joints[TORSO];
		    }
		    else if (trackRightHip) {
			m_HumanLastConfig[i].joints[RIGHT_HIP]=currentAgent->second.joints[RIGHT_HIP];
		    }

		    m_HumanRBuffer[i].push_back(humanRd.m_LastTime, m_HumanLastConfig[i]);
		    
		}
	    
		
		string centralJoint;
		if (trackTorso) {
		    centralJoint=TORSO;
		}
		else if (trackHead) {
		    centralJoint=HEAD;
		}

	
		
		//Compute monitors;:

		if (trackHead || trackTorso) {

		  bool isMoving=monitors.computeMotion(m_HumanRBuffer[i], centralJoint);
		  if (isMoving!=wasMoving[i]) {
		    oprsBridge.updateSupervisor("isMoving", i, isMoving, wasMoving[i]);
		    std::cout<<"isMoving "<<i<<" "<<isMoving<<"\n";
		  }
		wasMoving[i]=isMoving;

		bool isFacingRobot=monitors.computeOrientationToRobot(m_HumanLastConfig[i],  m_RobotLastConfig, centralJoint);
		string isFacing;
		if (isFacingRobot) {
		    isFacing="PR2";
		}
		    else {
			isFacing="OTHER";
		    }
		if (isFacing!=previousFacing[i]) {
		  std::cout<<"isFacing "<<i<<" "<<isFacing<<"\n";
		  oprsBridge.updateSupervisor("isFacing", i, isFacing, previousFacing[i]);
		}
		previousFacing[i]=isFacing;
		
		double distValue;
		string distance=monitors.computeDistance(m_HumanLastConfig[i], m_RobotLastConfig, centralJoint, &distValue);
		if (distance!=previousDistance[i]) {
		  std::cout<<"distance "<<i<<" "<<distance<<"\n";
		  oprsBridge.updateSupervisor("distance", i, distance,  previousDistance[i]);
		}
		previousDistance[i]=distance;

		if (distValue<minDistance) {
		  minAgent=i;
		}
		

		




		map<string,bool> handDistances;
		if (distance=="CLOSE" && trackRightHand && trackLeftHand) {

		    handDistances=monitors.computeHandDistance( m_HumanLastConfig[i],  m_RobotLastConfig);
		}
		else {
		    handDistances["LEFT"]=false;
		    handDistances["RIGHT"]=false;
		}

		if (handDistances["LEFT"]!=previousHandDistances[i]["LEFT"]) {

		    oprsBridge.updateSupervisor("closeToLeftGripper", i, handDistances["LEFT"], previousHandDistances[i]["LEFT"]);
		}

		if (handDistances["RIGHT"]!=previousHandDistances[i]["RIGHT"]) {

		    oprsBridge.updateSupervisor("closeToRightGripper", i, handDistances["RIGHT"],  previousHandDistances[i]["RIGHT"]);
		}

		previousHandDistances[i]["LEFT"]=handDistances["LEFT"];
		previousHandDistances[i]["RIGHT"]=handDistances["RIGHT"];

		}
		if (trackRightHand) {
		    string pose=monitors.computeAgentPose(m_HumanLastConfig[i]);
		    if (pose!=previousPose[i]) {
			oprsBridge.updateSupervisor("POSE", i, pose,  previousPose[i]);
		    }
		    
		    previousPose[i]=pose;	
		}
	    }
	   
	    if (minAgent!=closestAgent) {
	      std::stringstream ss;
	      ss<<minAgent;
	      oprsBridge.sendMessageOprs("add",robot,"isClosestTo",ss.str());
	      ss.str("");
	      ss<<closestAgent;
	      oprsBridge.sendMessageOprs("remove",robot,"isClosestTo",ss.str());
		closestAgent=minAgent;
	      std::cout<<"closestAgent"<<closestAgent<<"\n";
	    }
	}
}


		
  
		

