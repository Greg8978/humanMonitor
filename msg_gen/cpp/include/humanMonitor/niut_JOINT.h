/* Auto-generated by genmsg_cpp for file /home/gmilliez/work/ros_workspace/humanMonitor/msg/niut_JOINT.msg */
#ifndef HUMANMONITOR_MESSAGE_NIUT_JOINT_H
#define HUMANMONITOR_MESSAGE_NIUT_JOINT_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace humanMonitor
{
template <class ContainerAllocator>
struct niut_JOINT_ {
  typedef niut_JOINT_<ContainerAllocator> Type;

  niut_JOINT_()
  : value(0)
  {
  }

  niut_JOINT_(const ContainerAllocator& _alloc)
  : value(0)
  {
  }

  typedef uint32_t _value_type;
  uint32_t value;

  enum { niut_ZERO = 0 };
  enum { niut_HEAD = 1 };
  enum { niut_NECK = 2 };
  enum { niut_TORSO = 3 };
  enum { niut_WAIST = 4 };
  enum { niut_LEFT_COLLAR = 5 };
  enum { niut_LEFT_SHOULDER = 6 };
  enum { niut_LEFT_ELBOW = 7 };
  enum { niut_LEFT_WRIST = 8 };
  enum { niut_LEFT_HAND = 9 };
  enum { niut_LEFT_FINGERTIP = 10 };
  enum { niut_RIGHT_COLLAR = 11 };
  enum { niut_RIGHT_SHOULDER = 12 };
  enum { niut_RIGHT_ELBOW = 13 };
  enum { niut_RIGHT_WRIST = 14 };
  enum { niut_RIGHT_HAND = 15 };
  enum { niut_RIGHT_FINGERTIP = 16 };
  enum { niut_LEFT_HIP = 17 };
  enum { niut_LEFT_KNEE = 18 };
  enum { niut_LEFT_ANKLE = 19 };
  enum { niut_LEFT_FOOT = 20 };
  enum { niut_RIGHT_HIP = 21 };
  enum { niut_RIGHT_KNEE = 22 };
  enum { niut_RIGHT_ANKLE = 23 };
  enum { niut_RIGHT_FOOT = 24 };

  typedef boost::shared_ptr< ::humanMonitor::niut_JOINT_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::humanMonitor::niut_JOINT_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct niut_JOINT
typedef  ::humanMonitor::niut_JOINT_<std::allocator<void> > niut_JOINT;

typedef boost::shared_ptr< ::humanMonitor::niut_JOINT> niut_JOINTPtr;
typedef boost::shared_ptr< ::humanMonitor::niut_JOINT const> niut_JOINTConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::humanMonitor::niut_JOINT_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::humanMonitor::niut_JOINT_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace humanMonitor

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::humanMonitor::niut_JOINT_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::humanMonitor::niut_JOINT_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::humanMonitor::niut_JOINT_<ContainerAllocator> > {
  static const char* value() 
  {
    return "0e470f210f9f1090b60cbbd9da53831f";
  }

  static const char* value(const  ::humanMonitor::niut_JOINT_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x0e470f210f9f1090ULL;
  static const uint64_t static_value2 = 0xb60cbbd9da53831fULL;
};

template<class ContainerAllocator>
struct DataType< ::humanMonitor::niut_JOINT_<ContainerAllocator> > {
  static const char* value() 
  {
    return "humanMonitor/niut_JOINT";
  }

  static const char* value(const  ::humanMonitor::niut_JOINT_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::humanMonitor::niut_JOINT_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# IDL enum ::niut::JOINT\n\
uint32 niut_ZERO = 0\n\
uint32 niut_HEAD = 1\n\
uint32 niut_NECK = 2\n\
uint32 niut_TORSO = 3\n\
uint32 niut_WAIST = 4\n\
uint32 niut_LEFT_COLLAR = 5\n\
uint32 niut_LEFT_SHOULDER = 6\n\
uint32 niut_LEFT_ELBOW = 7\n\
uint32 niut_LEFT_WRIST = 8\n\
uint32 niut_LEFT_HAND = 9\n\
uint32 niut_LEFT_FINGERTIP = 10\n\
uint32 niut_RIGHT_COLLAR = 11\n\
uint32 niut_RIGHT_SHOULDER = 12\n\
uint32 niut_RIGHT_ELBOW = 13\n\
uint32 niut_RIGHT_WRIST = 14\n\
uint32 niut_RIGHT_HAND = 15\n\
uint32 niut_RIGHT_FINGERTIP = 16\n\
uint32 niut_LEFT_HIP = 17\n\
uint32 niut_LEFT_KNEE = 18\n\
uint32 niut_LEFT_ANKLE = 19\n\
uint32 niut_LEFT_FOOT = 20\n\
uint32 niut_RIGHT_HIP = 21\n\
uint32 niut_RIGHT_KNEE = 22\n\
uint32 niut_RIGHT_ANKLE = 23\n\
uint32 niut_RIGHT_FOOT = 24\n\
\n\
uint32 value\n\
\n\
";
  }

  static const char* value(const  ::humanMonitor::niut_JOINT_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::humanMonitor::niut_JOINT_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::humanMonitor::niut_JOINT_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.value);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct niut_JOINT_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::humanMonitor::niut_JOINT_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::humanMonitor::niut_JOINT_<ContainerAllocator> & v) 
  {
    s << indent << "value: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.value);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HUMANMONITOR_MESSAGE_NIUT_JOINT_H
