#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to flappy_robot_msgs__msg__FlappyStatus

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub pipe_positions: Vec<f32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub game_over_reason: std::string::String,

}



impl Default for FlappyStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FlappyStatus::default())
  }
}

impl rosidl_runtime_rs::Message for FlappyStatus {
  type RmwMsg = super::msg::rmw::FlappyStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vertical_velocity: msg.vertical_velocity,
        horizontal_speed: msg.horizontal_speed,
        score: msg.score,
        pipe_positions: msg.pipe_positions.into(),
        game_over_reason: msg.game_over_reason.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vertical_velocity: msg.vertical_velocity,
      horizontal_speed: msg.horizontal_speed,
      score: msg.score,
        pipe_positions: msg.pipe_positions.as_slice().into(),
        game_over_reason: msg.game_over_reason.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vertical_velocity: msg.vertical_velocity,
      horizontal_speed: msg.horizontal_speed,
      score: msg.score,
      pipe_positions: msg.pipe_positions
          .into_iter()
          .collect(),
      game_over_reason: msg.game_over_reason.to_string(),
    }
  }
}


