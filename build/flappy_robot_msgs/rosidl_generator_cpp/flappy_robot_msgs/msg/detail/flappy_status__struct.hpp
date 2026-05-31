// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice

#ifndef FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_HPP_
#define FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__flappy_robot_msgs__msg__FlappyStatus __attribute__((deprecated))
#else
# define DEPRECATED__flappy_robot_msgs__msg__FlappyStatus __declspec(deprecated)
#endif

namespace flappy_robot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FlappyStatus_
{
  using Type = FlappyStatus_<ContainerAllocator>;

  explicit FlappyStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vertical_velocity = 0.0f;
      this->horizontal_speed = 0.0f;
      this->score = 0l;
      this->game_over_reason = "";
    }
  }

  explicit FlappyStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : game_over_reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vertical_velocity = 0.0f;
      this->horizontal_speed = 0.0f;
      this->score = 0l;
      this->game_over_reason = "";
    }
  }

  // field types and members
  using _vertical_velocity_type =
    float;
  _vertical_velocity_type vertical_velocity;
  using _horizontal_speed_type =
    float;
  _horizontal_speed_type horizontal_speed;
  using _score_type =
    int32_t;
  _score_type score;
  using _pipe_positions_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _pipe_positions_type pipe_positions;
  using _game_over_reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _game_over_reason_type game_over_reason;

  // setters for named parameter idiom
  Type & set__vertical_velocity(
    const float & _arg)
  {
    this->vertical_velocity = _arg;
    return *this;
  }
  Type & set__horizontal_speed(
    const float & _arg)
  {
    this->horizontal_speed = _arg;
    return *this;
  }
  Type & set__score(
    const int32_t & _arg)
  {
    this->score = _arg;
    return *this;
  }
  Type & set__pipe_positions(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->pipe_positions = _arg;
    return *this;
  }
  Type & set__game_over_reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->game_over_reason = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__flappy_robot_msgs__msg__FlappyStatus
    std::shared_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__flappy_robot_msgs__msg__FlappyStatus
    std::shared_ptr<flappy_robot_msgs::msg::FlappyStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FlappyStatus_ & other) const
  {
    if (this->vertical_velocity != other.vertical_velocity) {
      return false;
    }
    if (this->horizontal_speed != other.horizontal_speed) {
      return false;
    }
    if (this->score != other.score) {
      return false;
    }
    if (this->pipe_positions != other.pipe_positions) {
      return false;
    }
    if (this->game_over_reason != other.game_over_reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const FlappyStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FlappyStatus_

// alias to use template instance with default allocator
using FlappyStatus =
  flappy_robot_msgs::msg::FlappyStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace flappy_robot_msgs

#endif  // FLAPPY_ROBOT_MSGS__MSG__DETAIL__FLAPPY_STATUS__STRUCT_HPP_
