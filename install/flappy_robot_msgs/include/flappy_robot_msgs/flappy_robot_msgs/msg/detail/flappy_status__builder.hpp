// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "flappy_robot_msgs/msg/flappy_status.hpp"


#ifndef FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__BUILDER_HPP_
#define FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flappy_robot_msgs/msg/detail/flappy_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flappy_robot_msgs
{

namespace msg
{

namespace builder
{

class Init_FlappyStatus_game_over_reason
{
public:
  explicit Init_FlappyStatus_game_over_reason(::flappy_robot_msgs::msg::FlappyStatus & msg)
  : msg_(msg)
  {}
  ::flappy_robot_msgs::msg::FlappyStatus game_over_reason(::flappy_robot_msgs::msg::FlappyStatus::_game_over_reason_type arg)
  {
    msg_.game_over_reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flappy_robot_msgs::msg::FlappyStatus msg_;
};

class Init_FlappyStatus_pipe_positions
{
public:
  explicit Init_FlappyStatus_pipe_positions(::flappy_robot_msgs::msg::FlappyStatus & msg)
  : msg_(msg)
  {}
  Init_FlappyStatus_game_over_reason pipe_positions(::flappy_robot_msgs::msg::FlappyStatus::_pipe_positions_type arg)
  {
    msg_.pipe_positions = std::move(arg);
    return Init_FlappyStatus_game_over_reason(msg_);
  }

private:
  ::flappy_robot_msgs::msg::FlappyStatus msg_;
};

class Init_FlappyStatus_score
{
public:
  explicit Init_FlappyStatus_score(::flappy_robot_msgs::msg::FlappyStatus & msg)
  : msg_(msg)
  {}
  Init_FlappyStatus_pipe_positions score(::flappy_robot_msgs::msg::FlappyStatus::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_FlappyStatus_pipe_positions(msg_);
  }

private:
  ::flappy_robot_msgs::msg::FlappyStatus msg_;
};

class Init_FlappyStatus_horizontal_speed
{
public:
  explicit Init_FlappyStatus_horizontal_speed(::flappy_robot_msgs::msg::FlappyStatus & msg)
  : msg_(msg)
  {}
  Init_FlappyStatus_score horizontal_speed(::flappy_robot_msgs::msg::FlappyStatus::_horizontal_speed_type arg)
  {
    msg_.horizontal_speed = std::move(arg);
    return Init_FlappyStatus_score(msg_);
  }

private:
  ::flappy_robot_msgs::msg::FlappyStatus msg_;
};

class Init_FlappyStatus_vertical_velocity
{
public:
  Init_FlappyStatus_vertical_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FlappyStatus_horizontal_speed vertical_velocity(::flappy_robot_msgs::msg::FlappyStatus::_vertical_velocity_type arg)
  {
    msg_.vertical_velocity = std::move(arg);
    return Init_FlappyStatus_horizontal_speed(msg_);
  }

private:
  ::flappy_robot_msgs::msg::FlappyStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flappy_robot_msgs::msg::FlappyStatus>()
{
  return flappy_robot_msgs::msg::builder::Init_FlappyStatus_vertical_velocity();
}

}  // namespace flappy_robot_msgs

#endif  // FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__BUILDER_HPP_
