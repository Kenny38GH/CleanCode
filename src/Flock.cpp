#include "../lib/Flock.hpp"

void Flock::update(const float &dT) {
  for (auto &boid : _boids) {
    boid.update(dT, in_fov_of(boid));
  }
}

void Flock::render(p6::Context &ctx, float &radius) {
  for (auto &boid : _boids) {
    boid.render(ctx, radius);
  }
}

void Flock::add_boid(const glm::vec2 &pos, float &speed) {
  _boids.push_back(Boid(pos, speed));
}

const std::vector<Boid *> Flock::in_fov_of(const Boid &boid) {
  std::vector<Boid *> return_vector;
  for (auto &b : _boids) {
    if (boid.sees(b)) {
      return_vector.push_back(&b);
    }
  }
  return return_vector;
}