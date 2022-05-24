#pragma once
#include "Boid.hpp"

#define DOG_SPEED 0.1f

class Doig : public Boid {
private:
  glm::vec2 _target;
  int _stun;

public:
  Doig() : Boid(glm::vec2(0)), _target(glm::vec2(0)), _stun(0) {}
  explicit Doig(glm::vec2 position)
      : Boid(position), _target(glm::vec2(0)), _stun(0) {}
  ~Doig() = default;

  void seek();
  inline void get_stunned() { _stun += 100; }
  inline void target(const glm::vec2 &target) { _target = target; }

  void update();
  void render(p6::Context &ctx, float &radius);

  void flee() = delete;
  void flock() = delete;
  void sees() = delete;
  void update_behaviour() = delete;
};