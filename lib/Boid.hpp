#pragma once
#include "render.hpp"

#define MAX_SPEED 1.f
#define MAX_ACCEL 1.0f

#define BASE_SPEED 0.05f
#define BASE_ACCEL 0.f
#define BASE_VIEW_RANGE 0.6f
#define BASE_VIEW_ANGLE 0.02f

enum class BEHAVIOUR : int { SEEK, FLEE, FLOCK };

class Boid {
private:
  glm::vec2 _velocity;
  glm::vec2 _acceleration;

  BEHAVIOUR _current_behaviour;

  float _view_range;
  float _view_angle;

public:
  Boid() = default;
  glm::vec2 _position;
  explicit Boid(const glm::vec2 position)
      : _position(position), _velocity(glm::vec2(BASE_SPEED)),
        _acceleration(BASE_ACCEL), _current_behaviour(BEHAVIOUR::SEEK),
        _view_range(BASE_VIEW_RANGE), _view_angle(BASE_VIEW_ANGLE) {}
  ~Boid() = default;

  void seek(const glm::vec2 &target);
  void flee(const glm::vec2 &target);
  void flock(const std::vector<Boid *> &nearest, const float &dT);

  bool sees(const Boid &boid) const;

  void update(const float &dT, const std::vector<Boid *> &nearests);
  const glm::vec2 update_behaviour(std::vector<Boid *> nearests);

  void render(p6::Context &ctx, float &radius);
};
