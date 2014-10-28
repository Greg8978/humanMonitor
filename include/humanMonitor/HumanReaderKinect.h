// A robot reader is a class that will read data from robot and fill 
// a timed ring buffer accordingly.

#include <ros/ros.h>
#include "humanMonitor/niut_HUMAN_LIST.h"
#include "humanMonitor/Agent.h"
#include "std_msgs/String.h"
#include <map> 
#include <string>
#include <sys/time.h>
#include <math.h>
#include <ostream>
#include "MathFunctions.h"

//#include "TRBuffer.h"



class HumanReaderKinect {

 public:
        //TRBuffer< map<std::String,bool> > m_RobotRingBuffer;
    std::map<int, Agent> m_LastConfig; 
    unsigned long m_LastTime;

    HumanReaderKinect(ros::NodeHandle& node, double * kinectPos); 
 
    bool isPresent(int i);


 private:

    void humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg);
    void projectJoint(AgentJoint joint, double* kinectPos, AgentJoint& jointW);

    double * kinectPos_;
    ros::Subscriber sub_;
    ros::NodeHandle node_;    


};
