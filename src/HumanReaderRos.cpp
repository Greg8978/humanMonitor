// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.


#include "humanMonitor/HumanReaderRos.h"



#define HumanReader_DEBUG 0

HumanReaderRos::HumanReaderRos(ros::NodeHandle& node, bool trackHead, bool trackRHand, string topic): node_(node){
  std::cout << "Initializing HumanReader" << std::endl;
  // ******************************************
  // Starts listening to the joint_states 
    sub = node_.subscribe(topic, 1, &HumanReaderRos::optitrackCallback, this);
    m_LastTime = 0;
    this->trackHead=trackHead;
    this->trackRHand=trackRHand;
    std::cout<< "Done\n";
}


void HumanReaderRos::optitrackCallback(const spencer_tracking_msgs::TrackedPersons::ConstPtr& msg) {
  
    tf::StampedTransform transform;
    tf::Transformer transformer;
    ros::Time now = ros::Time::now();
    
    bool USE_OPTITRACK_=true;
    string frame;
	
    //    std::cout<<"In callback\n";
    for (map<int, bool>::iterator i=presentAgents.begin(); i!=presentAgents.end(); i++) {
	i->second=false;
    }
    try {
      if (USE_OPTITRACK_) {
	frame=msg->header.frame_id;
	
	listener.waitForTransform("/map", frame,
				  msg->header.stamp, ros::Duration(3.0));
	listener.lookupTransform("/map", frame,
				 msg->header.stamp, transform);
      }

      for (int i=0; i<msg->tracks.size(); i++) {
	    spencer_tracking_msgs::TrackedPerson person=msg->tracks[i];   

	    presentAgents[person.track_id]=true;
	    geometry_msgs::PoseStamped optitrackPose, mapPose;
	    optitrackPose.pose.position=person.pose.pose.position;
	    optitrackPose.pose.orientation=person.pose.pose.orientation;
	    optitrackPose.header.stamp=msg->header.stamp;
	    optitrackPose.header.frame_id=frame;

	    //	    std::cout<<person.pose.pose.position.x<<"\n";
	    if (USE_OPTITRACK_) {
	      //	      std::cout<<transform.getOrigin().x()<<"\n";
	      //std::cout<<transform.getOrigin().y()<<"\n";
	      //std::cout<<transform.getOrigin().z()<<"\n";
	      // std::cout<<transform.getRotation().getAngle()<<"\n";

	      //listener.setTransform(transform);
	      //	    std::cout<<"transforming pose\n";
	      listener.transformPose("/map", optitrackPose,  mapPose);

	      //	    std::cout<<"transformed pose\n";

	      //     std::cout<<mapPose.pose.position.x<<"\n";
	    m_LastConfig[person.track_id].joints[HEAD].position.setX(mapPose.pose.position.x);
	    m_LastConfig[person.track_id].joints[HEAD].position.setY(mapPose.pose.position.y);
	    m_LastConfig[person.track_id].joints[HEAD].position.setZ(mapPose.pose.position.z);

	    // std::cout<<m_LastConfig[0].joints[0].position.x<<"\n";    
	    // std::cout<<m_LastConfig[0].joints[0].position.y<<"\n";
	    // std::cout<<m_LastConfig[0].joints[0].position.z<<"\n";
	
	    	tf:quaternionMsgToTF(mapPose.pose.orientation,  m_LastConfig[person.track_id].joints[HEAD].orientation);
	    }
	    else {
	      m_LastConfig[person.track_id].joints[HEAD].position.setX(optitrackPose.pose.position.x);
	      m_LastConfig[person.track_id].joints[HEAD].position.setY(optitrackPose.pose.position.y);
	      m_LastConfig[person.track_id].joints[HEAD].position.setZ(optitrackPose.pose.position.z);
	      tf::quaternionMsgToTF(optitrackPose.pose.orientation, m_LastConfig[person.track_id].joints[HEAD].orientation);
	   
	    }
	}
    }catch (tf::TransformException ex){
	ROS_ERROR("%s",ex.what());
	
    }
}


     




bool HumanReaderRos::isPresent(int i){
    return presentAgents[i];
}
