#include "../lib/Flock.hpp"

Flock::~Flock() { std::cout << _boids.size() << std::endl; }

void Flock::update(const float &dT, const glm::vec2 &mouse) {
  for (auto &boid : _boids) {
    boid.update(dT, in_fov_of(boid), _doig);
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

void Flock::add_boid(const glm::vec2 &pos) { _boids.push_back(Boid(pos)); }

const std::vector<Boid *> Flock::in_fov_of(const Boid &boid) {
  std::vector<Boid *> return_vector;
  for (auto &b : _boids) {
    if (boid.sees(b)) {
      return_vector.push_back(&b);
    }
  }
  return return_vector;
}