#pragma once

#include <glm/glm.hpp>
#include "render.hpp"
#include <iostream>

#define MAX_SPEED 100.0f
#define MAX_ACCEL 500.0f

#define BASE_SPEED 5.0f

class Boid {
private:
  glm::vec3 _position;
  glm::vec3 _velocity;
  glm::vec3 _acceleration;

  float _view_range;
  float _view_angle;

public:
  Boid() = default;
  Boid(glm::vec3 position)
      : _position(position), _velocity(glm::vec3(2.f, 2.f, 0.f)),
        _acceleration(0) {}
  ~Boid() = default;

  void seek(const glm::vec3 &target);
  void seek_away(const glm::vec3 &target);
  void update(const float &dT);

  void render() const;
};
