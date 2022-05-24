#pragma once

#include "Boid.hpp"
#include "Doig.hpp"
#include <vector>

class Flock {
private:
  // std::vector<Boid> _boids;
  Doig _doig;

public:
  Flock() = default;
  ~Flock() = default;
  std::vector<Boid> _boids;
  void reset() { _boids.clear(); };
  unsigned int get_size() { return _boids.size(); }
  void update(const float &dT, const glm::vec2 &mouse,
              glm::vec2 position_of_success);
  void render(p6::Context &ctx, float &radius);
  void add_boid(const glm::vec2 &pos, float &speed);
  const std::vector<Boid *> in_fov_of(const Boid &boid);
};