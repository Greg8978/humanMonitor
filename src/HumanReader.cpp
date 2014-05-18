// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.


#include <ostream>
#include "humanMonitor/HumanReader.h"
#define HumanReader_DEBUG 0

HumanReader::HumanReader(ros::NodeHandle& node): node_(node){
  std::cout << "Initializing HumanReader" << std::endl;
  // ******************************************
  // Starts listening to the joint_states topic
  // ******************************************

  sub = node_.subscribe("/niut/Human", 1, &HumanReader::humanJointCallBack, this);
  m_LastTime = 0;
}

void HumanReader::humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg){
//msg->filtered_users[i];
  std::cout << "we got message from niut" << std::endl;
  for(unsigned int i = 0; i < 16; i++){
    std::cout << "Test if there is a user" << std::endl;
    if( msg->filtered_users[i].trackedId > -1 ){
        std::cout << "There is a user!" << std::endl;
        m_LastConfig[msg->filtered_users[i].trackedId] = msg->filtered_users[i];
        m_LastTime = msg->filtered_users[i].date_discovered.t_sec * pow(10,9) + 
                     msg->filtered_users[i].date_discovered.t_usec;
        if(HumanReader_DEBUG){
            std::cout << "user's trackedId" << msg->filtered_users[i].trackedId << std::endl;
        }
    }
  }
  if(HumanReader_DEBUG){
    std::cout << std::endl;
  }
}

