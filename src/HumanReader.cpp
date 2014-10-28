// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.

#include <sys/time.h>
#include <math.h>
#include <ostream>
#include "humanMonitor/HumanReader.h"



#define HumanReader_DEBUG 0

HumanReader::HumanReader(ros::NodeHandle& node, bool USE_MOCAP): node_(node){
  std::cout << "Initializing HumanReader" << std::endl;
  // ******************************************
  // Starts listening to the joint_states topic
  // ******************************************

  if(USE_MOCAP==false) {
    sub = node_.subscribe("/niut/Human", 1, &HumanReader::humanJointCallBack, this);
  }
  else {
    sub = node_.subscribe("/optitrack_person/tracked_persons", 1, &HumanReader::optitrackCallback, this);
  }
  m_LastTime = 0;
}

void HumanReader::humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg){
    int niut_TORSO = 3;
    int niut_LEFT_HAND = 9;
    int niut_RIGHT_HAND = 15;
    int niut_RIGHT_HIP= 22;
    int niut_HEAD= 0;


//msg->filtered_users[i];
  for(int i=0; i<16; i++){
    if( msg->filtered_users[i].trackedId > -1 && msg->filtered_users[i].date.t_sec != 0){
      //        std::cout << "There is a user!" << std::endl;

      //Miki: had to do a loop on the joints since now the structure is different
	double x,y,z;
	x=msg->filtered_users[i].skeleton.joint[niut_TORSO].position.x;
	y=msg->filtered_users[i].skeleton.joint[niut_TORSO].position.y;
	z=msg->filtered_users[i].skeleton.joint[niut_TORSO].position.z;
	
	m_LastConfig[msg->filtered_users[i].trackedId].joints[TORSO].position.setX(x);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[TORSO].position.setY(y);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[TORSO].position.setZ(x);

	x=msg->filtered_users[i].skeleton.joint[niut_LEFT_HAND].position.x;
	y=msg->filtered_users[i].skeleton.joint[niut_LEFT_HAND].position.y;
	z=msg->filtered_users[i].skeleton.joint[niut_LEFT_HAND].position.z;
	
	m_LastConfig[msg->filtered_users[i].trackedId].joints[LEFT_HAND].position.setX(x);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[LEFT_HAND].position.setY(y);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[LEFT_HAND].position.setZ(z);


	x=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HAND].position.x;
	y=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HAND].position.y;
	z=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HAND].position.z;
	
	m_LastConfig[msg->filtered_users[i].trackedId].joints[RIGHT_HAND].position.setX(x);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[RIGHT_HAND].position.setY(y);
	m_LastConfig[msg->filtered_users[i].trackedId].joints[RIGHT_HAND].position.setZ(z);


	x=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HIP].position.x;
	y=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HIP].position.y;
	z=msg->filtered_users[i].skeleton.joint[niut_RIGHT_HIP].position.z;
	
	m_LastConfig[msg->filtered_users[i].trackedId].joints["RIGHT_HIP"].position.setX(x);
	m_LastConfig[msg->filtered_users[i].trackedId].joints["RIGHT_HIP"].position.setY(y);
	m_LastConfig[msg->filtered_users[i].trackedId].joints["RIGHT_HIP"].position.setZ(z);

	x=msg->filtered_users[i].skeleton.joint[niut_HEAD].position.x;
	y=msg->filtered_users[i].skeleton.joint[niut_HEAD].position.y;
	z=msg->filtered_users[i].skeleton.joint[niut_HEAD].position.z;
	
	m_LastConfig[msg->filtered_users[i].trackedId].joints["HEAD"].position.setX(x);
	m_LastConfig[msg->filtered_users[i].trackedId].joints["HEAD"].position.setY(y);
	m_LastConfig[msg->filtered_users[i].trackedId].joints["HEAD"].position.setZ(z);


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

void HumanReader::optitrackCallback(const spencer_tracking_msgs::TrackedPersons::ConstPtr& msg) {
  
    tf::StampedTransform transform;
    tf::Transformer transformer;
    ros::Time now = ros::Time::now();

    for (map<int, bool>::iterator i=presentAgents.begin(); i!=presentAgents.end(); i++) {
	i->second=false;
    }
    try {
	listener.waitForTransform("/map", "/optitrack",
				  now, ros::Duration(3.0));
	listener.lookupTransform("/map", "/optitrack",
				 now, transform);
	for (int i=0; i<msg->tracks.size(); i++) {
	    spencer_tracking_msgs::TrackedPerson person=msg->tracks[i];   

	    presentAgents[person.track_id]=true;
	    
	    geometry_msgs::PoseStamped optitrackPose, mapPose;
	    optitrackPose.pose.position=person.pose.pose.position;
	    optitrackPose.pose.orientation=person.pose.pose.orientation;
	    optitrackPose.header.stamp=ros::Time::now();
	    optitrackPose.header.frame_id="/optitrack";


	    //  listener.setTransform(transform);
	    std::cout<<"transforming pose\n";
	    listener.transformPose("/map", optitrackPose,  mapPose);

	    std::cout<<"transformed pose\n";

	    m_LastConfig[person.track_id].joints[HEAD].position.setX(mapPose.pose.position.x);
	    m_LastConfig[person.track_id].joints[HEAD].position.setY(mapPose.pose.position.y);
	    m_LastConfig[person.track_id].joints[HEAD].position.setZ(mapPose.pose.position.z);

	    // std::cout<<m_LastConfig[0].joints[0].position.x<<"\n";    
	    // std::cout<<m_LastConfig[0].joints[0].position.y<<"\n";
	    // std::cout<<m_LastConfig[0].joints[0].position.z<<"\n";
	
	tf:quaternionMsgToTF(mapPose.pose.orientation,  m_LastConfig[person.track_id].joints[HEAD].orientation);
	}
    }catch (tf::TransformException ex){
	ROS_ERROR("%s",ex.what());
	
    }
}


     




bool HumanReader::isPresent(){
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
