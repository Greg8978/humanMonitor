// A robot reader is a class that will read data from robot and fill 
// a timed ring buffer accordingly.

#include <ros/ros.h>
#include "humanMonitor/niut_HUMAN_LIST.h"
#include "std_msgs/String.h"
#include <map> 
#include <string> 
//#include "TRBuffer.h"

class HumanReader{

    public:
        //TRBuffer< map<std::String,bool> > m_RobotRingBuffer;
        std::map<int, humanMonitor::niut_USER_STR> m_LastConfig;
        uint64_t m_LastTime;

        HumanReader(ros::NodeHandle& node);

    private:
        ros::Subscriber sub;
        ros::NodeHandle node_;
        void humanJointCallBack(const humanMonitor::niut_HUMAN_LIST::ConstPtr& msg);
};
