// Generated by gencpp from file hw4_service_rectangle_area/RectangleAreaService.msg
// DO NOT EDIT!


#ifndef HW4_SERVICE_RECTANGLE_AREA_MESSAGE_RECTANGLEAREASERVICE_H
#define HW4_SERVICE_RECTANGLE_AREA_MESSAGE_RECTANGLEAREASERVICE_H

#include <ros/service_traits.h>


#include <hw4_service_rectangle_area/RectangleAreaServiceRequest.h>
#include <hw4_service_rectangle_area/RectangleAreaServiceResponse.h>


namespace hw4_service_rectangle_area
{

struct RectangleAreaService
{

typedef RectangleAreaServiceRequest Request;
typedef RectangleAreaServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct RectangleAreaService
} // namespace hw4_service_rectangle_area


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::hw4_service_rectangle_area::RectangleAreaService > {
  static const char* value()
  {
    return "92e9c8f940da77dc3e1bc289f7dd146e";
  }

  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaService&) { return value(); }
};

template<>
struct DataType< ::hw4_service_rectangle_area::RectangleAreaService > {
  static const char* value()
  {
    return "hw4_service_rectangle_area/RectangleAreaService";
  }

  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaService&) { return value(); }
};


// service_traits::MD5Sum< ::hw4_service_rectangle_area::RectangleAreaServiceRequest> should match
// service_traits::MD5Sum< ::hw4_service_rectangle_area::RectangleAreaService >
template<>
struct MD5Sum< ::hw4_service_rectangle_area::RectangleAreaServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::hw4_service_rectangle_area::RectangleAreaService >::value();
  }
  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::hw4_service_rectangle_area::RectangleAreaServiceRequest> should match
// service_traits::DataType< ::hw4_service_rectangle_area::RectangleAreaService >
template<>
struct DataType< ::hw4_service_rectangle_area::RectangleAreaServiceRequest>
{
  static const char* value()
  {
    return DataType< ::hw4_service_rectangle_area::RectangleAreaService >::value();
  }
  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::hw4_service_rectangle_area::RectangleAreaServiceResponse> should match
// service_traits::MD5Sum< ::hw4_service_rectangle_area::RectangleAreaService >
template<>
struct MD5Sum< ::hw4_service_rectangle_area::RectangleAreaServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::hw4_service_rectangle_area::RectangleAreaService >::value();
  }
  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::hw4_service_rectangle_area::RectangleAreaServiceResponse> should match
// service_traits::DataType< ::hw4_service_rectangle_area::RectangleAreaService >
template<>
struct DataType< ::hw4_service_rectangle_area::RectangleAreaServiceResponse>
{
  static const char* value()
  {
    return DataType< ::hw4_service_rectangle_area::RectangleAreaService >::value();
  }
  static const char* value(const ::hw4_service_rectangle_area::RectangleAreaServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HW4_SERVICE_RECTANGLE_AREA_MESSAGE_RECTANGLEAREASERVICE_H
