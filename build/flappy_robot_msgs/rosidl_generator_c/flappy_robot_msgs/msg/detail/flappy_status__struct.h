// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "flappy_robot_msgs/msg/flappy_status.h"


#ifndef FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_H_
#define FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'pipe_positions'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'game_over_reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FlappyStatus in the package flappy_robot_msgs.
typedef struct flappy_robot_msgs__msg__FlappyStatus
{
  float vertical_velocity;
  float horizontal_speed;
  int32_t score;
  rosidl_runtime_c__float__Sequence pipe_positions;
  rosidl_runtime_c__String game_over_reason;
} flappy_robot_msgs__msg__FlappyStatus;

// Struct for a sequence of flappy_robot_msgs__msg__FlappyStatus.
typedef struct flappy_robot_msgs__msg__FlappyStatus__Sequence
{
  flappy_robot_msgs__msg__FlappyStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flappy_robot_msgs__msg__FlappyStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_H_
