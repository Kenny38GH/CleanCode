#include "../lib/Doig.hpp"

void Doig::update() {

  seek();

  if (_stun == 0) {
    if (glm::length(_velocity + _acceleration * 0.017f) < MAX_SPEED) {
      _velocity.x += _acceleration.x * 0.017f;
      _velocity.y += _acceleration.y * 0.017f;
    }
    std::cout << "ok" << std::endl;
  } else {
    _stun--;
  }

  _position += (_velocity * BASE_SPEED) * 0.08f;
  _acceleration -= _acceleration * 0.05f; // ARBITRAIRE
}

void Doig::render(p6::Context &ctx, float &radius) {
  display_doggo(ctx, _position, _velocity, radius);
}