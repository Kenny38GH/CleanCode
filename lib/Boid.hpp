#pragma once
#include "random.hpp"
#include "render.hpp"

#define MAX_SPEED 0.1f
#define MAX_ACCEL 0.2f

#define BASE_SPEED 0.05f
#define BASE_ACCEL 0.f
#define BASE_VIEW_RANGE 0.5f
#define BASE_VIEW_ANGLE 20.f

enum class BEHAVIOUR : int { SEEK, FLEE, FLOCK };

class Doig;

class Boid {
private:
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  float _max_speed;

  BEHAVIOUR _current_behaviour;

  float _view_range;
  float _view_angle;

  friend class Doig;

public:
  Boid() = default;
  bool is_muffin_time = false;
  glm::vec2 _position;
  explicit Boid(const glm::vec2 position, float speed)
      : _position(position), _max_speed(speed),
        _velocity(glm::vec2(BASE_SPEED * primary_rand() * heads_or_tails(),
                            BASE_SPEED * primary_rand() * heads_or_tails())),
        _acceleration(BASE_ACCEL), _current_behaviour(BEHAVIOUR::SEEK),
        _view_range(BASE_VIEW_RANGE), _view_angle(BASE_VIEW_ANGLE) {}
  Boid(const glm::vec2 position)
      : _position(position),
        _velocity(glm::vec2(BASE_SPEED * primary_rand() * heads_or_tails(),
                            BASE_SPEED * primary_rand() * heads_or_tails())),
        _acceleration(BASE_ACCEL), _current_behaviour(BEHAVIOUR::SEEK),
        _view_range(BASE_VIEW_RANGE), _view_angle(BASE_VIEW_ANGLE) {}
  ~Boid() = default;

  void seek(const glm::vec2 &target);
  void flee(const glm::vec2 &target);
  void flock(const std::vector<Boid *> &nearest, const float &dT);

  bool sees(const Boid &boid) const;
  bool sees(const Doig &doig) const;

  void update(const float &dT, const std::vector<Boid *> &nearests,
              const Doig &doig, glm::vec2 position_of_success);
  const glm::vec2 update_behaviour(std::vector<Boid *> nearests,
                                   const Doig &doig);
  void check_success(glm::vec2 _position_of_success);
  void render(p6::Context &ctx, float &radius);
  void charge(const glm::vec2 &target);
};
