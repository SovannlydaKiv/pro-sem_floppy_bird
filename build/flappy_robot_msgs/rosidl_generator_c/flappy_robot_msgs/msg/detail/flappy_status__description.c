// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

#include "flappy_robot_msgs/msg/detail/flappy_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_flappy_robot_msgs
const rosidl_type_hash_t *
flappy_robot_msgs__msg__FlappyStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x23, 0x04, 0x40, 0xb2, 0xff, 0xd5, 0x30, 0x38,
      0xd7, 0x7c, 0xb7, 0xc8, 0xf3, 0x95, 0x7f, 0x85,
      0xe7, 0x2f, 0xc3, 0x78, 0xa7, 0x4c, 0x24, 0x93,
      0x5f, 0xf5, 0x2b, 0xc9, 0xce, 0x04, 0x8a, 0x97,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char flappy_robot_msgs__msg__FlappyStatus__TYPE_NAME[] = "flappy_robot_msgs/msg/FlappyStatus";

// Define type names, field names, and default values
static char flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__vertical_velocity[] = "vertical_velocity";
static char flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__horizontal_speed[] = "horizontal_speed";
static char flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__score[] = "score";
static char flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__pipe_positions[] = "pipe_positions";
static char flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__game_over_reason[] = "game_over_reason";

static rosidl_runtime_c__type_description__Field flappy_robot_msgs__msg__FlappyStatus__FIELDS[] = {
  {
    {flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__vertical_velocity, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__horizontal_speed, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__score, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__pipe_positions, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {flappy_robot_msgs__msg__FlappyStatus__FIELD_NAME__game_over_reason, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
flappy_robot_msgs__msg__FlappyStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {flappy_robot_msgs__msg__FlappyStatus__TYPE_NAME, 34, 34},
      {flappy_robot_msgs__msg__FlappyStatus__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 vertical_velocity\n"
  "float32 horizontal_speed\n"
  "int32 score\n"
  "float32[] pipe_positions\n"
  "string game_over_reason";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
flappy_robot_msgs__msg__FlappyStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {flappy_robot_msgs__msg__FlappyStatus__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 112, 112},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
flappy_robot_msgs__msg__FlappyStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *flappy_robot_msgs__msg__FlappyStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
