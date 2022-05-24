#pragma once

#include "Boid.hpp"
#include "Doig.hpp"
#include <vector>

class Flock {
private:
  std::vector<Boid> _boids;
  Doig _doig;

public:
  Flock() = default;
  ~Flock();

  void update(const float &dT, const glm::vec2 &mouse);
  void render(p6::Context &ctx, float &radius);
  void add_boid(const glm::vec2 &pos);
  const std::vector<Boid *> in_fov_of(const Boid &boid);
};