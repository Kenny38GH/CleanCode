#pragma once

#include "render_assets.hpp"
#include "render_shape.hpp"
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

#define MAX_SPEED 12.0f
#define MAX_ACCEL 40.0f

#define BASE_SPEED 5.0f
#define BASE_ACCEL 0.f
#define BASE_VIEW_RANGE 60
#define BASE_VIEW_ANGLE 270

enum class BEHAVIOUR : int { SEEK, FLEE, FLOCK };

class Boid {
private:
  glm::vec3 _position;
  glm::vec3 _velocity;
  glm::vec3 _acceleration;

  BEHAVIOUR _current_behaviour;

  float _view_range;
  float _view_angle;

public:
  Boid() = default;
  explicit Boid(const glm::vec3 &position)
      : _position(position), _velocity(glm::vec3(BASE_SPEED)),
        _acceleration(BASE_ACCEL), _current_behaviour(BEHAVIOUR::SEEK),
        _view_range(BASE_VIEW_RANGE), _view_angle(BASE_VIEW_ANGLE) {}
  ~Boid() = default;

  void seek(const glm::vec3 &target);
  void flee(const glm::vec3 &target);
  void flock(const std::vector<Boid *> &nearest, const float &dT);

  bool sees(const Boid &boid) const;

  void update(const float &dT, const std::vector<Boid *> &nearests);
  const glm::vec3 update_behaviour(std::vector<Boid *> nearests);

  void render() const;
};