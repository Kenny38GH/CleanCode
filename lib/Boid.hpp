#pragma once
#include "render.hpp"

#define MAX_SPEED 8.0f
#define MAX_ACCEL 500.0f

#define BASE_SPEED 1.f

class Boid {
private:
  glm::vec2 _velocity;
  glm::vec2 _acceleration;

  float _view_range;
  float _view_angle;

public:
  Boid() = default;
  glm::vec2 _position;
  Boid(glm::vec2 position)
      : _position(position), _velocity(glm::vec2(1.f, 1.f)), _acceleration(0) {}
  ~Boid() = default;

  void seek(const glm::vec2 &target);
  void seek_away(const glm::vec2 &target);
  void update(const float &dT);
};
