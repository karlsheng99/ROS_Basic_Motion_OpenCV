// Generated by gencpp from file ros_basics_tutorials/Add2Ints.msg
// DO NOT EDIT!


#ifndef ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTS_H
#define ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTS_H

#include <ros/service_traits.h>


#include <ros_basics_tutorials/Add2IntsRequest.h>
#include <ros_basics_tutorials/Add2IntsResponse.h>


namespace ros_basics_tutorials
{

struct Add2Ints
{

typedef Add2IntsRequest Request;
typedef Add2IntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Add2Ints
} // namespace ros_basics_tutorials


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ros_basics_tutorials::Add2Ints > {
  static const char* value()
  {
    return "6a2e34150c00229791cc89ff309fff21";
  }

  static const char* value(const ::ros_basics_tutorials::Add2Ints&) { return value(); }
};

template<>
struct DataType< ::ros_basics_tutorials::Add2Ints > {
  static const char* value()
  {
    return "ros_basics_tutorials/Add2Ints";
  }

  static const char* value(const ::ros_basics_tutorials::Add2Ints&) { return value(); }
};


// service_traits::MD5Sum< ::ros_basics_tutorials::Add2IntsRequest> should match
// service_traits::MD5Sum< ::ros_basics_tutorials::Add2Ints >
template<>
struct MD5Sum< ::ros_basics_tutorials::Add2IntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ros_basics_tutorials::Add2Ints >::value();
  }
  static const char* value(const ::ros_basics_tutorials::Add2IntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ros_basics_tutorials::Add2IntsRequest> should match
// service_traits::DataType< ::ros_basics_tutorials::Add2Ints >
template<>
struct DataType< ::ros_basics_tutorials::Add2IntsRequest>
{
  static const char* value()
  {
    return DataType< ::ros_basics_tutorials::Add2Ints >::value();
  }
  static const char* value(const ::ros_basics_tutorials::Add2IntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ros_basics_tutorials::Add2IntsResponse> should match
// service_traits::MD5Sum< ::ros_basics_tutorials::Add2Ints >
template<>
struct MD5Sum< ::ros_basics_tutorials::Add2IntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ros_basics_tutorials::Add2Ints >::value();
  }
  static const char* value(const ::ros_basics_tutorials::Add2IntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ros_basics_tutorials::Add2IntsResponse> should match
// service_traits::DataType< ::ros_basics_tutorials::Add2Ints >
template<>
struct DataType< ::ros_basics_tutorials::Add2IntsResponse>
{
  static const char* value()
  {
    return DataType< ::ros_basics_tutorials::Add2Ints >::value();
  }
  static const char* value(const ::ros_basics_tutorials::Add2IntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROS_BASICS_TUTORIALS_MESSAGE_ADD2INTS_H
