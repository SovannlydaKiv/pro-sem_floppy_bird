// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice
#ifndef FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "flappy_robot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_serialize_flappy_robot_msgs__msg__FlappyStatus(
  const flappy_robot_msgs__msg__FlappyStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_deserialize_flappy_robot_msgs__msg__FlappyStatus(
  eprosima::fastcdr::Cdr &,
  flappy_robot_msgs__msg__FlappyStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t get_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t max_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_serialize_key_flappy_robot_msgs__msg__FlappyStatus(
  const flappy_robot_msgs__msg__FlappyStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t get_serialized_size_key_flappy_robot_msgs__msg__FlappyStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t max_serialized_size_key_flappy_robot_msgs__msg__FlappyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, flappy_robot_msgs, msg, FlappyStatus)();

#ifdef __cplusplus
}
#endif

#endif  // FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
