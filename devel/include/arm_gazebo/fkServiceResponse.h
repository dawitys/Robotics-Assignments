// Generated by gencpp from file arm_gazebo/fkServiceResponse.msg
// DO NOT EDIT!


#ifndef ARM_GAZEBO_MESSAGE_FKSERVICERESPONSE_H
#define ARM_GAZEBO_MESSAGE_FKSERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace arm_gazebo
{
template <class ContainerAllocator>
struct fkServiceResponse_
{
  typedef fkServiceResponse_<ContainerAllocator> Type;

  fkServiceResponse_()
    : ee()  {
    }
  fkServiceResponse_(const ContainerAllocator& _alloc)
    : ee(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _ee_type;
  _ee_type ee;





  typedef boost::shared_ptr< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct fkServiceResponse_

typedef ::arm_gazebo::fkServiceResponse_<std::allocator<void> > fkServiceResponse;

typedef boost::shared_ptr< ::arm_gazebo::fkServiceResponse > fkServiceResponsePtr;
typedef boost::shared_ptr< ::arm_gazebo::fkServiceResponse const> fkServiceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arm_gazebo::fkServiceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::arm_gazebo::fkServiceResponse_<ContainerAllocator1> & lhs, const ::arm_gazebo::fkServiceResponse_<ContainerAllocator2> & rhs)
{
  return lhs.ee == rhs.ee;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::arm_gazebo::fkServiceResponse_<ContainerAllocator1> & lhs, const ::arm_gazebo::fkServiceResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace arm_gazebo

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "65babecddad448c19eadaa319f462d2d";
  }

  static const char* value(const ::arm_gazebo::fkServiceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x65babecddad448c1ULL;
  static const uint64_t static_value2 = 0x9eadaa319f462d2dULL;
};

template<class ContainerAllocator>
struct DataType< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arm_gazebo/fkServiceResponse";
  }

  static const char* value(const ::arm_gazebo::fkServiceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[] ee\n"
;
  }

  static const char* value(const ::arm_gazebo::fkServiceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ee);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct fkServiceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arm_gazebo::fkServiceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arm_gazebo::fkServiceResponse_<ContainerAllocator>& v)
  {
    s << indent << "ee[]" << std::endl;
    for (size_t i = 0; i < v.ee.size(); ++i)
    {
      s << indent << "  ee[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.ee[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARM_GAZEBO_MESSAGE_FKSERVICERESPONSE_H
