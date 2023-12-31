// Generated by gencpp from file ros_basics_tutorials/Add2IntsRequest.msg
// DO NOT EDIT!


#ifndef ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTSREQUEST_H
#define ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTSREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_basics_tutorials
{
template <class ContainerAllocator>
struct Add2IntsRequest_
{
  typedef Add2IntsRequest_<ContainerAllocator> Type;

  Add2IntsRequest_()
    : a(0)
    , b(0)  {
    }
  Add2IntsRequest_(const ContainerAllocator& _alloc)
    : a(0)
    , b(0)  {
  (void)_alloc;
    }



   typedef int64_t _a_type;
  _a_type a;

   typedef int64_t _b_type;
  _b_type b;





  typedef boost::shared_ptr< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct Add2IntsRequest_

typedef ::ros_basics_tutorials::Add2IntsRequest_<std::allocator<void> > Add2IntsRequest;

typedef boost::shared_ptr< ::ros_basics_tutorials::Add2IntsRequest > Add2IntsRequestPtr;
typedef boost::shared_ptr< ::ros_basics_tutorials::Add2IntsRequest const> Add2IntsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator1> & lhs, const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator2> & rhs)
{
  return lhs.a == rhs.a &&
    lhs.b == rhs.b;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator1> & lhs, const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_basics_tutorials

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "36d09b846be0b371c5f190354dd3153e";
  }

  static const char* value(const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x36d09b846be0b371ULL;
  static const uint64_t static_value2 = 0xc5f190354dd3153eULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_basics_tutorials/Add2IntsRequest";
  }

  static const char* value(const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 a\n"
"int64 b\n"
;
  }

  static const char* value(const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a);
      stream.next(m.b);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Add2IntsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_basics_tutorials::Add2IntsRequest_<ContainerAllocator>& v)
  {
    s << indent << "a: ";
    Printer<int64_t>::stream(s, indent + "  ", v.a);
    s << indent << "b: ";
    Printer<int64_t>::stream(s, indent + "  ", v.b);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTSREQUEST_H
