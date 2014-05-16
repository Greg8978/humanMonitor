// A robot reader is a class that will read data from robot and fill 
// a timed ring buffer accordingly.

#include <ros/ros.h>
#include "tf/transform_listener.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/String.h"
#include <map> 
#include <string> 
//#include "TRBuffer.h"

class RobotReader{

    public:
        //TRBuffer< map<std::String,bool> > m_RobotRingBuffer;
        std::map<std::string, float> m_LastConfig;
        uint64_t m_LastTime;

        RobotReader(ros::NodeHandle& node);

    private:
        ros::Subscriber sub;
        ros::NodeHandle node_;
        tf::TransformListener m_Listener;

        void getPr2Location(tf::TransformListener& listener);
        void pr2JointStateCallBack(const sensor_msgs::JointState::ConstPtr& msg);
};
