#include "../lib/Doig.hpp"

void Doig::seek() {
  glm::vec2 desired = _target - _position;
  desired = glm::normalize(desired) * DOG_SPEED;
  glm::vec2 steer = desired - _velocity;

  if (glm::length(_acceleration + steer) < 2 * DOG_SPEED)
    _acceleration += steer;
}

void Doig::update() {

  seek();

  if (_stun == 0) {
    if (glm::length(_velocity + _acceleration * 0.017f) < MAX_SPEED) {
      _velocity.x += _acceleration.x * 0.017f;
      _velocity.y += _acceleration.y * 0.017f;
    }
  } else {
    _stun--;
  }

  _position += (_velocity * BASE_SPEED) * 0.4f;
  _acceleration -= _acceleration * 0.1f; // ARBITRAIRE
}

void Doig::render(p6::Context &ctx, float &radius) {
  display_doggo(ctx, _position, _velocity, radius);
}