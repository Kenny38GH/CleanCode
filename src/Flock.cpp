#include "../lib/Flock.hpp"

void Flock::update(const float &dT, const glm::vec2 &mouse,
                   glm::vec2 position_of_success) {
  int i = 0;
  for (auto &boid : _boids) {
    boid.update(dT, in_fov_of(boid), _doig, position_of_success);
    if (boid.is_muffin_time) {
      _boids.erase(_boids.begin() + i);
    }
    i += 1;
  }
  _doig.target(mouse);
  _doig.update();
}

void Flock::render(p6::Context &ctx, float &radius) {
  for (auto &boid : _boids) {
    boid.render(ctx, radius);
  }
  _doig.render(ctx, radius);
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