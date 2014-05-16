/* Auto-generated by genmsg_cpp for file /home/gmilliez/work/ros_workspace/humanMonitor/msg/niut_GEN_POINT_3D.msg */
#ifndef HUMANMONITOR_MESSAGE_NIUT_GEN_POINT_3D_H
#define HUMANMONITOR_MESSAGE_NIUT_GEN_POINT_3D_H
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
struct niut_GEN_POINT_3D_ {
  typedef niut_GEN_POINT_3D_<ContainerAllocator> Type;

  niut_GEN_POINT_3D_()
  : x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  niut_GEN_POINT_3D_(const ContainerAllocator& _alloc)
  : x(0.0)
  , y(0.0)
  , z(0.0)
  {
  }

  typedef double _x_type;
  double x;

  typedef double _y_type;
  double y;

  typedef double _z_type;
  double z;


  typedef boost::shared_ptr< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct niut_GEN_POINT_3D
typedef  ::humanMonitor::niut_GEN_POINT_3D_<std::allocator<void> > niut_GEN_POINT_3D;

typedef boost::shared_ptr< ::humanMonitor::niut_GEN_POINT_3D> niut_GEN_POINT_3DPtr;
typedef boost::shared_ptr< ::humanMonitor::niut_GEN_POINT_3D const> niut_GEN_POINT_3DConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace humanMonitor

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const  ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "humanMonitor/niut_GEN_POINT_3D";
  }

  static const char* value(const  ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# IDL struct ::niut::GEN_POINT_3D\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
";
  }

  static const char* value(const  ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.z);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct niut_GEN_POINT_3D_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::humanMonitor::niut_GEN_POINT_3D_<ContainerAllocator> & v) 
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HUMANMONITOR_MESSAGE_NIUT_GEN_POINT_3D_H
