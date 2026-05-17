// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "flappy_robot_msgs/msg/detail/flappy_status__rosidl_typesupport_introspection_c.h"
#include "flappy_robot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__functions.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__struct.h"


// Include directives for member types
// Member `pipe_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `game_over_reason`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  flappy_robot_msgs__msg__FlappyStatus__init(message_memory);
}

void flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_fini_function(void * message_memory)
{
  flappy_robot_msgs__msg__FlappyStatus__fini(message_memory);
}

size_t flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__size_function__FlappyStatus__pipe_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_const_function__FlappyStatus__pipe_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_function__FlappyStatus__pipe_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__fetch_function__FlappyStatus__pipe_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_const_function__FlappyStatus__pipe_positions(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__assign_function__FlappyStatus__pipe_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_function__FlappyStatus__pipe_positions(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__resize_function__FlappyStatus__pipe_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_member_array[5] = {
  {
    "vertical_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs__msg__FlappyStatus, vertical_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "horizontal_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs__msg__FlappyStatus, horizontal_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs__msg__FlappyStatus, score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pipe_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs__msg__FlappyStatus, pipe_positions),  // bytes offset in struct
    NULL,  // default value
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__size_function__FlappyStatus__pipe_positions,  // size() function pointer
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_const_function__FlappyStatus__pipe_positions,  // get_const(index) function pointer
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__get_function__FlappyStatus__pipe_positions,  // get(index) function pointer
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__fetch_function__FlappyStatus__pipe_positions,  // fetch(index, &value) function pointer
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__assign_function__FlappyStatus__pipe_positions,  // assign(index, value) function pointer
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__resize_function__FlappyStatus__pipe_positions  // resize(index) function pointer
  },
  {
    "game_over_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(flappy_robot_msgs__msg__FlappyStatus, game_over_reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_members = {
  "flappy_robot_msgs__msg",  // message namespace
  "FlappyStatus",  // message name
  5,  // number of fields
  sizeof(flappy_robot_msgs__msg__FlappyStatus),
  false,  // has_any_key_member_
  flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_member_array,  // message members
  flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_type_support_handle = {
  0,
  &flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_members,
  get_message_typesupport_handle_function,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_hash,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_description,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_flappy_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, flappy_robot_msgs, msg, FlappyStatus)() {
  if (!flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_type_support_handle.typesupport_identifier) {
    flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &flappy_robot_msgs__msg__FlappyStatus__rosidl_typesupport_introspection_c__FlappyStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
