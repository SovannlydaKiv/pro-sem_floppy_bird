// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice
#include "flappy_robot_msgs/msg/detail/flappy_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "flappy_robot_msgs/msg/detail/flappy_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace flappy_robot_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flappy_robot_msgs
cdr_serialize(
  const flappy_robot_msgs::msg::FlappyStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: vertical_velocity
  cdr << ros_message.vertical_velocity;
  // Member: horizontal_speed
  cdr << ros_message.horizontal_speed;
  // Member: score
  cdr << ros_message.score;
  // Member: pipe_positions
  {
    cdr << ros_message.pipe_positions;
  }
  // Member: game_over_reason
  cdr << ros_message.game_over_reason;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flappy_robot_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  flappy_robot_msgs::msg::FlappyStatus & ros_message)
{
  // Member: vertical_velocity
  cdr >> ros_message.vertical_velocity;

  // Member: horizontal_speed
  cdr >> ros_message.horizontal_speed;

  // Member: score
  cdr >> ros_message.score;

  // Member: pipe_positions
  {
    cdr >> ros_message.pipe_positions;
  }

  // Member: game_over_reason
  cdr >> ros_message.game_over_reason;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flappy_robot_msgs
get_serialized_size(
  const flappy_robot_msgs::msg::FlappyStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: vertical_velocity
  {
    size_t item_size = sizeof(ros_message.vertical_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: horizontal_speed
  {
    size_t item_size = sizeof(ros_message.horizontal_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: score
  {
    size_t item_size = sizeof(ros_message.score);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pipe_positions
  {
    size_t array_size = ros_message.pipe_positions.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.pipe_positions[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: game_over_reason
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.game_over_reason.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_flappy_robot_msgs
max_serialized_size_FlappyStatus(
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


  // Member: vertical_velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: horizontal_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: score
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pipe_positions
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

  // Member: game_over_reason
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
    using DataType = flappy_robot_msgs::msg::FlappyStatus;
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
  auto typed_message =
    static_cast<const flappy_robot_msgs::msg::FlappyStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FlappyStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<flappy_robot_msgs::msg::FlappyStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FlappyStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const flappy_robot_msgs::msg::FlappyStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FlappyStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FlappyStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FlappyStatus__callbacks = {
  "flappy_robot_msgs::msg",
  "FlappyStatus",
  _FlappyStatus__cdr_serialize,
  _FlappyStatus__cdr_deserialize,
  _FlappyStatus__get_serialized_size,
  _FlappyStatus__max_serialized_size
};

static rosidl_message_type_support_t _FlappyStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FlappyStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace flappy_robot_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_flappy_robot_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<flappy_robot_msgs::msg::FlappyStatus>()
{
  return &flappy_robot_msgs::msg::typesupport_fastrtps_cpp::_FlappyStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, flappy_robot_msgs, msg, FlappyStatus)() {
  return &flappy_robot_msgs::msg::typesupport_fastrtps_cpp::_FlappyStatus__handle;
}

#ifdef __cplusplus
}
#endif
