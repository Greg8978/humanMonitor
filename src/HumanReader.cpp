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
  m_LastTime = 0;
}

void HumanReader::humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg){
//msg->filtered_users[i];
  for(int i=0; i<16; i++){
    if( msg->filtered_users[i].trackedId > -1 && msg->filtered_users[i].date.t_sec != 0){
      //        std::cout << "There is a user!" << std::endl;

      //Miki: had to do a loop on the joints since now the structure is different
      for (int j=0; j<25; j++) {
	m_LastConfig[msg->filtered_users[i].trackedId].joints[j].position= msg->filtered_users[i].skeleton.joint[j].position;
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

void HumanReader::updateHuman(tf::TransformListener &listener) {
  getHumanJointLocation(listener, 0, "person_1");
}

void HumanReader::getHumanJointLocation(tf::TransformListener &listener, int joint, std::string personId) {
  //Miki: for now the parameter joint is ignored because we only use the head of the person with mocap
  //for now this is implemented for just one agent (and probably doesn't work even in that case XD). Must be corrected
  
   tf::StampedTransform transform;
   std::string transformId = "/";
   transformId.append(personId);
   try{
     ros::Time now = ros::Time::now();
     listener.waitForTransform("/map", transformId,
			       now, ros::Duration(3.0));
     listener.lookupTransform("/map", transformId,
                              now, transform);
     
     m_LastConfig[0].joints[joint].position.x = transform.getOrigin().x();
     m_LastConfig[0].joints[joint].position.y = transform.getOrigin().y();
     m_LastConfig[0].joints[joint].position.z = transform.getOrigin().z();
     
     m_LastConfig[0].joints[joint].orientation=transform.getRotation();

   }    
   catch (tf::TransformException ex){
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
