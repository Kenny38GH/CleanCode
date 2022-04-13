#pragma once

#include <glm/glm.hpp>
#include "render.hpp"
#include <iostream>
#include <vector>


#define MAX_SPEED 15.0f
#define MAX_ACCEL 40.0f

#define BASE_SPEED 5.0f

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
      : _position(position), _velocity(glm::vec3(2.f, 2.f, 0.f)),
        _acceleration(0), _current_behaviour(BEHAVIOUR::SEEK), _view_range(60),
        _view_angle(270) {}
  ~Boid() = default;

  void seek(const glm::vec3 &target);
  void flee(const glm::vec3 &target);
  void flock(const std::vector<Boid*> &nearest, const float &dT);

  bool sees(const Boid &boid) const;

  void update(const float &dT, std::vector<Boid*> nearests);
  const glm::vec3 update_behaviour(std::vector<Boid*> nearests);

  void render() const;
};