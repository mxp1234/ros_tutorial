// Generated by gencpp from file plumbing_pub_sub/data.msg
// DO NOT EDIT!


#ifndef PLUMBING_PUB_SUB_MESSAGE_DATA_H
#define PLUMBING_PUB_SUB_MESSAGE_DATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace plumbing_pub_sub
{
template <class ContainerAllocator>
struct data_
{
  typedef data_<ContainerAllocator> Type;

  data_()
    : name()
    , age(0)
    , height(0.0)  {
    }
  data_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , age(0)
    , height(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef int32_t _age_type;
  _age_type age;

   typedef float _height_type;
  _height_type height;





  typedef boost::shared_ptr< ::plumbing_pub_sub::data_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::plumbing_pub_sub::data_<ContainerAllocator> const> ConstPtr;

}; // struct data_

typedef ::plumbing_pub_sub::data_<std::allocator<void> > data;

typedef boost::shared_ptr< ::plumbing_pub_sub::data > dataPtr;
typedef boost::shared_ptr< ::plumbing_pub_sub::data const> dataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::plumbing_pub_sub::data_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::plumbing_pub_sub::data_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::plumbing_pub_sub::data_<ContainerAllocator1> & lhs, const ::plumbing_pub_sub::data_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.age == rhs.age &&
    lhs.height == rhs.height;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::plumbing_pub_sub::data_<ContainerAllocator1> & lhs, const ::plumbing_pub_sub::data_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace plumbing_pub_sub

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::plumbing_pub_sub::data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::plumbing_pub_sub::data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::plumbing_pub_sub::data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::plumbing_pub_sub::data_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::plumbing_pub_sub::data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::plumbing_pub_sub::data_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::plumbing_pub_sub::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0478132ca0c3bd1c734b5491000dabb1";
  }

  static const char* value(const ::plumbing_pub_sub::data_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0478132ca0c3bd1cULL;
  static const uint64_t static_value2 = 0x734b5491000dabb1ULL;
};

template<class ContainerAllocator>
struct DataType< ::plumbing_pub_sub::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "plumbing_pub_sub/data";
  }

  static const char* value(const ::plumbing_pub_sub::data_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::plumbing_pub_sub::data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n"
"int32 age\n"
"float32 height\n"
;
  }

  static const char* value(const ::plumbing_pub_sub::data_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::plumbing_pub_sub::data_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.age);
      stream.next(m.height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct data_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::plumbing_pub_sub::data_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::plumbing_pub_sub::data_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "age: ";
    Printer<int32_t>::stream(s, indent + "  ", v.age);
    s << indent << "height: ";
    Printer<float>::stream(s, indent + "  ", v.height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLUMBING_PUB_SUB_MESSAGE_DATA_H
