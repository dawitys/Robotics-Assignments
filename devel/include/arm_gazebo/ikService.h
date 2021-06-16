// Generated by gencpp from file arm_gazebo/ikService.msg
// DO NOT EDIT!


#ifndef ARM_GAZEBO_MESSAGE_IKSERVICE_H
#define ARM_GAZEBO_MESSAGE_IKSERVICE_H

#include <ros/service_traits.h>


#include <arm_gazebo/ikServiceRequest.h>
#include <arm_gazebo/ikServiceResponse.h>


namespace arm_gazebo
{

struct ikService
{

typedef ikServiceRequest Request;
typedef ikServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ikService
} // namespace arm_gazebo


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::arm_gazebo::ikService > {
  static const char* value()
  {
    return "739e17d373aedcc76ba2f276406c2579";
  }

  static const char* value(const ::arm_gazebo::ikService&) { return value(); }
};

template<>
struct DataType< ::arm_gazebo::ikService > {
  static const char* value()
  {
    return "arm_gazebo/ikService";
  }

  static const char* value(const ::arm_gazebo::ikService&) { return value(); }
};


// service_traits::MD5Sum< ::arm_gazebo::ikServiceRequest> should match
// service_traits::MD5Sum< ::arm_gazebo::ikService >
template<>
struct MD5Sum< ::arm_gazebo::ikServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::arm_gazebo::ikService >::value();
  }
  static const char* value(const ::arm_gazebo::ikServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::arm_gazebo::ikServiceRequest> should match
// service_traits::DataType< ::arm_gazebo::ikService >
template<>
struct DataType< ::arm_gazebo::ikServiceRequest>
{
  static const char* value()
  {
    return DataType< ::arm_gazebo::ikService >::value();
  }
  static const char* value(const ::arm_gazebo::ikServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::arm_gazebo::ikServiceResponse> should match
// service_traits::MD5Sum< ::arm_gazebo::ikService >
template<>
struct MD5Sum< ::arm_gazebo::ikServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::arm_gazebo::ikService >::value();
  }
  static const char* value(const ::arm_gazebo::ikServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::arm_gazebo::ikServiceResponse> should match
// service_traits::DataType< ::arm_gazebo::ikService >
template<>
struct DataType< ::arm_gazebo::ikServiceResponse>
{
  static const char* value()
  {
    return DataType< ::arm_gazebo::ikService >::value();
  }
  static const char* value(const ::arm_gazebo::ikServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ARM_GAZEBO_MESSAGE_IKSERVICE_H