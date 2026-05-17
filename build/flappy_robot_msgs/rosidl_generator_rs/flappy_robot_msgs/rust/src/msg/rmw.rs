#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "flappy_robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__flappy_robot_msgs__msg__FlappyStatus() -> *const std::ffi::c_void;
}

#[link(name = "flappy_robot_msgs__rosidl_generator_c")]
extern "C" {
    fn flappy_robot_msgs__msg__FlappyStatus__init(msg: *mut FlappyStatus) -> bool;
    fn flappy_robot_msgs__msg__FlappyStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FlappyStatus>, size: usize) -> bool;
    fn flappy_robot_msgs__msg__FlappyStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FlappyStatus>);
    fn flappy_robot_msgs__msg__FlappyStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FlappyStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<FlappyStatus>) -> bool;
}

// Corresponds to flappy_robot_msgs__msg__FlappyStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FlappyStatus {

    // This member is not documented.
    #[allow(missing_docs)]
    pub vertical_velocity: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub horizontal_speed: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub score: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pipe_positions: rosidl_runtime_rs::Sequence<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub game_over_reason: rosidl_runtime_rs::String,

}



impl Default for FlappyStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !flappy_robot_msgs__msg__FlappyStatus__init(&mut msg as *mut _) {
        panic!("Call to flappy_robot_msgs__msg__FlappyStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FlappyStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { flappy_robot_msgs__msg__FlappyStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { flappy_robot_msgs__msg__FlappyStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { flappy_robot_msgs__msg__FlappyStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FlappyStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FlappyStatus where Self: Sized {
  const TYPE_NAME: &'static str = "flappy_robot_msgs/msg/FlappyStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__flappy_robot_msgs__msg__FlappyStatus() }
  }
}


