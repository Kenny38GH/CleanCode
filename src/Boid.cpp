#include "../lib/Boid.hpp"

void Boid::seek(const glm::vec2 &target) {
  glm::vec2 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec2 steer = desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::seek_away(const glm::vec2 &target) {
  glm::vec2 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec2 steer = -desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::update(const float &dT) {
  // Position update
  _position.x += (_velocity.x * BASE_SPEED) * dT;
  _position.y += (_velocity.y * BASE_SPEED) * dT;

  // _velocitye update
  if (glm::length(_velocity + _acceleration) < MAX_SPEED) {
    _velocity.x += _acceleration.x * dT;
    _velocity.y += _acceleration.y * dT;
  }

  _acceleration = glm::vec2(0);
}
