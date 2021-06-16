// Generated by gencpp from file arm_gazebo/fkService.msg
// DO NOT EDIT!


#ifndef ARM_GAZEBO_MESSAGE_FKSERVICE_H
#define ARM_GAZEBO_MESSAGE_FKSERVICE_H

#include <ros/service_traits.h>


#include <arm_gazebo/fkServiceRequest.h>
#include <arm_gazebo/fkServiceResponse.h>


namespace arm_gazebo
{

struct fkService
{

typedef fkServiceRequest Request;
typedef fkServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct fkService
} // namespace arm_gazebo


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::arm_gazebo::fkService > {
  static const char* value()
  {
    return "7064256d7c8bd8994ec62c2cfe279a6e";
  }

  static const char* value(const ::arm_gazebo::fkService&) { return value(); }
};

template<>
struct DataType< ::arm_gazebo::fkService > {
  static const char* value()
  {
    return "arm_gazebo/fkService";
  }

  static const char* value(const ::arm_gazebo::fkService&) { return value(); }
};


// service_traits::MD5Sum< ::arm_gazebo::fkServiceRequest> should match
// service_traits::MD5Sum< ::arm_gazebo::fkService >
template<>
struct MD5Sum< ::arm_gazebo::fkServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::arm_gazebo::fkService >::value();
  }
  static const char* value(const ::arm_gazebo::fkServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::arm_gazebo::fkServiceRequest> should match
// service_traits::DataType< ::arm_gazebo::fkService >
template<>
struct DataType< ::arm_gazebo::fkServiceRequest>
{
  static const char* value()
  {
    return DataType< ::arm_gazebo::fkService >::value();
  }
  static const char* value(const ::arm_gazebo::fkServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::arm_gazebo::fkServiceResponse> should match
// service_traits::MD5Sum< ::arm_gazebo::fkService >
template<>
struct MD5Sum< ::arm_gazebo::fkServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::arm_gazebo::fkService >::value();
  }
  static const char* value(const ::arm_gazebo::fkServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::arm_gazebo::fkServiceResponse> should match
// service_traits::DataType< ::arm_gazebo::fkService >
template<>
struct DataType< ::arm_gazebo::fkServiceResponse>
{
  static const char* value()
  {
    return DataType< ::arm_gazebo::fkService >::value();
  }
  static const char* value(const ::arm_gazebo::fkServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ARM_GAZEBO_MESSAGE_FKSERVICE_H