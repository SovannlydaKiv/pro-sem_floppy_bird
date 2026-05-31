// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from flappy_robot_msgs:msg/FlappyStatus.idl
// generated code does not contain a copyright notice
#include "flappy_robot_msgs/msg/detail/flappy_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pipe_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `game_over_reason`
#include "rosidl_runtime_c/string_functions.h"

bool
flappy_robot_msgs__msg__FlappyStatus__init(flappy_robot_msgs__msg__FlappyStatus * msg)
{
  if (!msg) {
    return false;
  }
  // vertical_velocity
  // horizontal_speed
  // score
  // pipe_positions
  if (!rosidl_runtime_c__float__Sequence__init(&msg->pipe_positions, 0)) {
    flappy_robot_msgs__msg__FlappyStatus__fini(msg);
    return false;
  }
  // game_over_reason
  if (!rosidl_runtime_c__String__init(&msg->game_over_reason)) {
    flappy_robot_msgs__msg__FlappyStatus__fini(msg);
    return false;
  }
  return true;
}

void
flappy_robot_msgs__msg__FlappyStatus__fini(flappy_robot_msgs__msg__FlappyStatus * msg)
{
  if (!msg) {
    return;
  }
  // vertical_velocity
  // horizontal_speed
  // score
  // pipe_positions
  rosidl_runtime_c__float__Sequence__fini(&msg->pipe_positions);
  // game_over_reason
  rosidl_runtime_c__String__fini(&msg->game_over_reason);
}

bool
flappy_robot_msgs__msg__FlappyStatus__are_equal(const flappy_robot_msgs__msg__FlappyStatus * lhs, const flappy_robot_msgs__msg__FlappyStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vertical_velocity
  if (lhs->vertical_velocity != rhs->vertical_velocity) {
    return false;
  }
  // horizontal_speed
  if (lhs->horizontal_speed != rhs->horizontal_speed) {
    return false;
  }
  // score
  if (lhs->score != rhs->score) {
    return false;
  }
  // pipe_positions
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->pipe_positions), &(rhs->pipe_positions)))
  {
    return false;
  }
  // game_over_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->game_over_reason), &(rhs->game_over_reason)))
  {
    return false;
  }
  return true;
}

bool
flappy_robot_msgs__msg__FlappyStatus__copy(
  const flappy_robot_msgs__msg__FlappyStatus * input,
  flappy_robot_msgs__msg__FlappyStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // vertical_velocity
  output->vertical_velocity = input->vertical_velocity;
  // horizontal_speed
  output->horizontal_speed = input->horizontal_speed;
  // score
  output->score = input->score;
  // pipe_positions
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->pipe_positions), &(output->pipe_positions)))
  {
    return false;
  }
  // game_over_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->game_over_reason), &(output->game_over_reason)))
  {
    return false;
  }
  return true;
}

flappy_robot_msgs__msg__FlappyStatus *
flappy_robot_msgs__msg__FlappyStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flappy_robot_msgs__msg__FlappyStatus * msg = (flappy_robot_msgs__msg__FlappyStatus *)allocator.allocate(sizeof(flappy_robot_msgs__msg__FlappyStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(flappy_robot_msgs__msg__FlappyStatus));
  bool success = flappy_robot_msgs__msg__FlappyStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
flappy_robot_msgs__msg__FlappyStatus__destroy(flappy_robot_msgs__msg__FlappyStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    flappy_robot_msgs__msg__FlappyStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
flappy_robot_msgs__msg__FlappyStatus__Sequence__init(flappy_robot_msgs__msg__FlappyStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flappy_robot_msgs__msg__FlappyStatus * data = NULL;

  if (size) {
    data = (flappy_robot_msgs__msg__FlappyStatus *)allocator.zero_allocate(size, sizeof(flappy_robot_msgs__msg__FlappyStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = flappy_robot_msgs__msg__FlappyStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        flappy_robot_msgs__msg__FlappyStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
flappy_robot_msgs__msg__FlappyStatus__Sequence__fini(flappy_robot_msgs__msg__FlappyStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      flappy_robot_msgs__msg__FlappyStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

flappy_robot_msgs__msg__FlappyStatus__Sequence *
flappy_robot_msgs__msg__FlappyStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  flappy_robot_msgs__msg__FlappyStatus__Sequence * array = (flappy_robot_msgs__msg__FlappyStatus__Sequence *)allocator.allocate(sizeof(flappy_robot_msgs__msg__FlappyStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = flappy_robot_msgs__msg__FlappyStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
flappy_robot_msgs__msg__FlappyStatus__Sequence__destroy(flappy_robot_msgs__msg__FlappyStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    flappy_robot_msgs__msg__FlappyStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
flappy_robot_msgs__msg__FlappyStatus__Sequence__are_equal(const flappy_robot_msgs__msg__FlappyStatus__Sequence * lhs, const flappy_robot_msgs__msg__FlappyStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!flappy_robot_msgs__msg__FlappyStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
flappy_robot_msgs__msg__FlappyStatus__Sequence__copy(
  const flappy_robot_msgs__msg__FlappyStatus__Sequence * input,
  flappy_robot_msgs__msg__FlappyStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(flappy_robot_msgs__msg__FlappyStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    flappy_robot_msgs__msg__FlappyStatus * data =
      (flappy_robot_msgs__msg__FlappyStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!flappy_robot_msgs__msg__FlappyStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          flappy_robot_msgs__msg__FlappyStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!flappy_robot_msgs__msg__FlappyStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
