// A robot reader is a class that will read data from robot and fill 
// a timed ring buffer accordingly.

#include <ros/ros.h>
#include "humanMonitor/Agent.h"
#include "tf/transform_listener.h"
#include "std_msgs/String.h"
#include <map> 
#include <string>
#include "geometry_msgs/PoseStamped.h"
#include "spencer_tracking_msgs/TrackedPersons.h"
#include "spencer_tracking_msgs/TrackedPerson.h"
 #include "tf/transform_listener.h"
#include <sys/time.h>
#include <math.h>
#include <ostream>


class HumanReaderRos{

    public:
        //TRBuffer< map<std::String,bool> > m_RobotRingBuffer;
    std::map<int, Agent> m_LastConfig;  //Miki: switched to human like outside.
    std::map<int, bool> presentAgents;
    unsigned long m_LastTime;

    HumanReaderRos(ros::NodeHandle& node, bool trackHead, bool trackRHand, string topic); //Miki: here I added a flag for MOCAP. The humanJointCallback is not used if the flag is true.
 
        bool isPresent(int i);


    private:
        ros::Subscriber sub;
        ros::NodeHandle node_;
	void optitrackCallback(const spencer_tracking_msgs::TrackedPersons::ConstPtr& msg);
	void getHumanJointLocation(tf::TransformListener &listener, int joint, std::string personId); //Miki: support functions for the joints called by updateHuman (we only have one joint at the moment with MOCAP but still XD) 
	  tf::TransformListener listener;

	  bool trackHead;
	  bool trackRHand;


};
