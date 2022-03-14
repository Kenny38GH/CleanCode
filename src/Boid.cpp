#include "../lib/Boid.hpp"

void Boid::seek(const glm::vec3 &target) {
  glm::vec3 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec3 steer = desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::flee(const glm::vec3 &target) {
  glm::vec3 desired = target - _position;
  desired = glm::normalize(desired) * MAX_SPEED;
  glm::vec3 steer = -desired - _velocity;

  if (glm::length(_acceleration + steer) < MAX_ACCEL)
    _acceleration += steer;
}

void Boid::update(const double &dT) {
  // Position update
  _position.x += (_velocity.x * BASE_SPEED) * static_cast<float>(dT);
  _position.y += (_velocity.y * BASE_SPEED) * static_cast<float>(dT);

  // _velocitye update
  if (glm::length(_velocity + _acceleration) < MAX_SPEED) {
    _velocity.x += _acceleration.x * static_cast<float>(dT);
    _velocity.y += _acceleration.y * static_cast<float>(dT);
  }

  _acceleration = glm::vec3(0);
}

void Boid::render() const { render_triangle(_position, _velocity, 10.f); }