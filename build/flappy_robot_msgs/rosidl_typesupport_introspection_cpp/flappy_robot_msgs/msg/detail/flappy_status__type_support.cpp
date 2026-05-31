// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace flappy_robot_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FlappyStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) flappy_robot_msgs::msg::FlappyStatus(_init);
}

void FlappyStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<flappy_robot_msgs::msg::FlappyStatus *>(message_memory);
  typed_message->~FlappyStatus();
}

size_t size_function__FlappyStatus__pipe_positions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FlappyStatus__pipe_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__FlappyStatus__pipe_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__FlappyStatus__pipe_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__FlappyStatus__pipe_positions(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__FlappyStatus__pipe_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__FlappyStatus__pipe_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__FlappyStatus__pipe_positions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FlappyStatus_message_member_array[5] = {
  {
    "vertical_velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs::msg::FlappyStatus, vertical_velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "horizontal_speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs::msg::FlappyStatus, horizontal_speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "score",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs::msg::FlappyStatus, score),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pipe_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs::msg::FlappyStatus, pipe_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__FlappyStatus__pipe_positions,  // size() function pointer
    get_const_function__FlappyStatus__pipe_positions,  // get_const(index) function pointer
    get_function__FlappyStatus__pipe_positions,  // get(index) function pointer
    fetch_function__FlappyStatus__pipe_positions,  // fetch(index, &value) function pointer
    assign_function__FlappyStatus__pipe_positions,  // assign(index, value) function pointer
    resize_function__FlappyStatus__pipe_positions  // resize(index) function pointer
  },
  {
    "game_over_reason",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs::msg::FlappyStatus, game_over_reason),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FlappyStatus_message_members = {
  "flappy_robot_msgs::msg",  // message namespace
  "FlappyStatus",  // message name
  5,  // number of fields
  sizeof(flappy_robot_msgs::msg::FlappyStatus),
  FlappyStatus_message_member_array,  // message members
  FlappyStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  FlappyStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FlappyStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FlappyStatus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace flappy_robot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<flappy_robot_msgs::msg::FlappyStatus>()
{
  return &::flappy_robot_msgs::msg::rosidl_typesupport_introspection_cpp::FlappyStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, flappy_robot_msgs, msg, FlappyStatus)() {
  return &::flappy_robot_msgs::msg::rosidl_typesupport_introspection_cpp::FlappyStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
