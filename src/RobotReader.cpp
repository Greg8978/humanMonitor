// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.


#include <ostream>
#include "humanMonitor/RobotReader.h"
#define RobotReader_DEBUG 0

RobotReader::RobotReader(ros::NodeHandle& node):node_(node){

  // ******************************************
  // Starts listening to the joint_states topic
  // ******************************************

  sub = node_.subscribe("joint_states", 1, &RobotReader::pr2JointStateCallBack, this);
  m_LastTime = 0;
}

void RobotReader::getPr2Location(tf::TransformListener& listener){
    tf::StampedTransform transform;
    try{
        ros::Time now = ros::Time::now();
        listener.waitForTransform("/map", "/base_link",
                              now, ros::Duration(3.0));
        listener.lookupTransform("/map", "/base_link",
                               now, transform);
        m_LastTime = now.toNSec();
        if(RobotReader_DEBUG){
          std::cout << "Ros Time = " << m_LastTime << std::endl;
        }
        m_LastConfig["poseX"] = transform.getOrigin().x();
        m_LastConfig["poseY"] = transform.getOrigin().y();
        m_LastConfig["poseZ"] = transform.getOrigin().z();

        if(RobotReader_DEBUG){
          printf("%f %f %f\n", transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z());
        }
    }    
    catch (tf::TransformException ex){
        ROS_ERROR("%s",ex.what());
    }
}
void RobotReader::pr2JointStateCallBack(const sensor_msgs::JointState::ConstPtr& msg){

  //First, get the base pr2 pose
  getPr2Location(m_Listener);

  for(unsigned int i = 0; i < msg->position.size(); i++){
    m_LastConfig[msg->name[i].c_str()] = msg->position[i];
    if(RobotReader_DEBUG){
      std::cout << msg->name[i] << "   " << msg->position[i] << std::endl;
    }
  }
  if(RobotReader_DEBUG){
    std::cout << std::endl;
  }
}

