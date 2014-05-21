// A human reader is a class that will read data from human(s) and fill 
// a timed ring buffer accordingly.

#include <sys/time.h>
#include <math.h>
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
  for(int i=0; i<16; i++){
    if( msg->filtered_users[i].trackedId > -1 && msg->filtered_users[i].date.t_sec != 0){
        std::cout << "There is a user!" << std::endl;
        m_LastConfig[msg->filtered_users[i].trackedId] = msg->filtered_users[i];
        m_LastTime = msg->filtered_users[i].date.t_sec * pow(10,9) + 
                     msg->filtered_users[i].date.t_usec;
        std::cout << "time from callback " << m_LastTime << std::endl;
        if(HumanReader_DEBUG){
            std::cout << "user's trackedId" << msg->filtered_users[i].trackedId << std::endl;
        }
    }
  }
  if(HumanReader_DEBUG){
    std::cout << std::endl;
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
