#pragma once

#include "Boid.hpp"
#include <vector>

class Flock {
private:
  std::vector<Boid> _boids;

public:
  Flock() = default;
  ~Flock();

  void update(const float &dT);
  void render(p6::Context &ctx, float &radius);
  void add_boid(const glm::vec2 &pos);
  const std::vector<Boid *> in_fov_of(const Boid &boid);
};