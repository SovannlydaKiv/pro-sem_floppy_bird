// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "flappy_robot_msgs/msg/flappy_status.hpp"


#ifndef FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__TRAITS_HPP_
#define FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flappy_robot_msgs/msg/detail/flappy_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flappy_robot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FlappyStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: vertical_velocity
  {
    out << "vertical_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_velocity, out);
    out << ", ";
  }

  // member: horizontal_speed
  {
    out << "horizontal_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_speed, out);
    out << ", ";
  }

  // member: score
  {
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << ", ";
  }

  // member: pipe_positions
  {
    if (msg.pipe_positions.size() == 0) {
      out << "pipe_positions: []";
    } else {
      out << "pipe_positions: [";
      size_t pending_items = msg.pipe_positions.size();
      for (auto item : msg.pipe_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: game_over_reason
  {
    out << "game_over_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.game_over_reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FlappyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vertical_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vertical_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_velocity, out);
    out << "\n";
  }

  // member: horizontal_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "horizontal_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_speed, out);
    out << "\n";
  }

  // member: score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << "\n";
  }

  // member: pipe_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pipe_positions.size() == 0) {
      out << "pipe_positions: []\n";
    } else {
      out << "pipe_positions:\n";
      for (auto item : msg.pipe_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: game_over_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "game_over_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.game_over_reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FlappyStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace flappy_robot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use flappy_robot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flappy_robot_msgs::msg::FlappyStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  flappy_robot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flappy_robot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const flappy_robot_msgs::msg::FlappyStatus & msg)
{
  return flappy_robot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flappy_robot_msgs::msg::FlappyStatus>()
{
  return "flappy_robot_msgs::msg::FlappyStatus";
}

template<>
inline const char * name<flappy_robot_msgs::msg::FlappyStatus>()
{
  return "flappy_robot_msgs/msg/FlappyStatus";
}

template<>
struct has_fixed_size<flappy_robot_msgs::msg::FlappyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<flappy_robot_msgs::msg::FlappyStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<flappy_robot_msgs::msg::FlappyStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__TRAITS_HPP_
