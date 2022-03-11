#pragma once

#include "Boid.hpp"
#include <vector>

class Flock {
private:
  std::vector<Boid> _boids;

public:
  Flock() = default;
  ~Flock();

  void update(const Uint32 &dT, const glm::vec3 &point_to_seek);
  void render();
  void add_boid(const glm::vec3 &pos);
};