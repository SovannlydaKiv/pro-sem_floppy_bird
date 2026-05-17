// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice
#include "flappy_robot_msgs/msg/detail/flappy_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "flappy_robot_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__struct.h"
#include "flappy_robot_msgs/msg/detail/flappy_status__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // pipe_positions
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // pipe_positions
#include "rosidl_runtime_c/string.h"  // game_over_reason
#include "rosidl_runtime_c/string_functions.h"  // game_over_reason

// forward declare type support functions


using _FlappyStatus__ros_msg_type = flappy_robot_msgs__msg__FlappyStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_serialize_flappy_robot_msgs__msg__FlappyStatus(
  const flappy_robot_msgs__msg__FlappyStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: vertical_velocity
  {
    cdr << ros_message->vertical_velocity;
  }

  // Field name: horizontal_speed
  {
    cdr << ros_message->horizontal_speed;
  }

  // Field name: score
  {
    cdr << ros_message->score;
  }

  // Field name: pipe_positions
  {
    size_t size = ros_message->pipe_positions.size;
    auto array_ptr = ros_message->pipe_positions.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: game_over_reason
  {
    const rosidl_runtime_c__String * str = &ros_message->game_over_reason;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_deserialize_flappy_robot_msgs__msg__FlappyStatus(
  eprosima::fastcdr::Cdr & cdr,
  flappy_robot_msgs__msg__FlappyStatus * ros_message)
{
  // Field name: vertical_velocity
  {
    cdr >> ros_message->vertical_velocity;
  }

  // Field name: horizontal_speed
  {
    cdr >> ros_message->horizontal_speed;
  }

  // Field name: score
  {
    cdr >> ros_message->score;
  }

  // Field name: pipe_positions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->pipe_positions.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->pipe_positions);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->pipe_positions, size)) {
      fprintf(stderr, "failed to create array for field 'pipe_positions'");
      return false;
    }
    auto array_ptr = ros_message->pipe_positions.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: game_over_reason
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->game_over_reason.data) {
      rosidl_runtime_c__String__init(&ros_message->game_over_reason);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->game_over_reason,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'game_over_reason'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t get_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FlappyStatus__ros_msg_type * ros_message = static_cast<const _FlappyStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: vertical_velocity
  {
    size_t item_size = sizeof(ros_message->vertical_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: horizontal_speed
  {
    size_t item_size = sizeof(ros_message->horizontal_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: score
  {
    size_t item_size = sizeof(ros_message->score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pipe_positions
  {
    size_t array_size = ros_message->pipe_positions.size;
    auto array_ptr = ros_message->pipe_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: game_over_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->game_over_reason.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t max_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: vertical_velocity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: horizontal_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: score
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pipe_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: game_over_reason
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = flappy_robot_msgs__msg__FlappyStatus;
    is_plain =
      (
      offsetof(DataType, game_over_reason) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
bool cdr_serialize_key_flappy_robot_msgs__msg__FlappyStatus(
  const flappy_robot_msgs__msg__FlappyStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: vertical_velocity
  {
    cdr << ros_message->vertical_velocity;
  }

  // Field name: horizontal_speed
  {
    cdr << ros_message->horizontal_speed;
  }

  // Field name: score
  {
    cdr << ros_message->score;
  }

  // Field name: pipe_positions
  {
    size_t size = ros_message->pipe_positions.size;
    auto array_ptr = ros_message->pipe_positions.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: game_over_reason
  {
    const rosidl_runtime_c__String * str = &ros_message->game_over_reason;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t get_serialized_size_key_flappy_robot_msgs__msg__FlappyStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FlappyStatus__ros_msg_type * ros_message = static_cast<const _FlappyStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: vertical_velocity
  {
    size_t item_size = sizeof(ros_message->vertical_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: horizontal_speed
  {
    size_t item_size = sizeof(ros_message->horizontal_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: score
  {
    size_t item_size = sizeof(ros_message->score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pipe_positions
  {
    size_t array_size = ros_message->pipe_positions.size;
    auto array_ptr = ros_message->pipe_positions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: game_over_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->game_over_reason.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_flappy_robot_msgs
size_t max_serialized_size_key_flappy_robot_msgs__msg__FlappyStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: vertical_velocity
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: horizontal_speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: score
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pipe_positions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: game_over_reason
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = flappy_robot_msgs__msg__FlappyStatus;
    is_plain =
      (
      offsetof(DataType, game_over_reason) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FlappyStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const flappy_robot_msgs__msg__FlappyStatus * ros_message = static_cast<const flappy_robot_msgs__msg__FlappyStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_flappy_robot_msgs__msg__FlappyStatus(ros_message, cdr);
}

static bool _FlappyStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  flappy_robot_msgs__msg__FlappyStatus * ros_message = static_cast<flappy_robot_msgs__msg__FlappyStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_flappy_robot_msgs__msg__FlappyStatus(cdr, ros_message);
}

static uint32_t _FlappyStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
      untyped_ros_message, 0));
}

static size_t _FlappyStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_flappy_robot_msgs__msg__FlappyStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FlappyStatus = {
  "flappy_robot_msgs::msg",
  "FlappyStatus",
  _FlappyStatus__cdr_serialize,
  _FlappyStatus__cdr_deserialize,
  _FlappyStatus__get_serialized_size,
  _FlappyStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FlappyStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FlappyStatus,
  get_message_typesupport_handle_function,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_hash,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_description,
  &flappy_robot_msgs__msg__FlappyStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, flappy_robot_msgs, msg, FlappyStatus)() {
  return &_FlappyStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
