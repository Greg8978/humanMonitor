#include <ros/ros.h>

#include "humanMonitor/HumanReader.h"
#include "humanMonitor/RobotReader.h"

int main(int argc, char** argv){

  ros::init(argc, argv, "humanMonitor");
  ros::NodeHandle node;

  HumanReader humanRd(node);
  RobotReader robotRd(node);
  
  while( node.ok() ){
    std::cout << "Last human time received " << humanRd.m_LastTime << std::endl;
    std::cout << "number of human received " << humanRd.m_LastConfig.size() << std::endl;
    
    std::cout << "Last robot time received " << robotRd.m_LastTime << std::endl;
    std::cout << "number of robot joint received " << robotRd.m_LastConfig.size() << std::endl;
  }

}
