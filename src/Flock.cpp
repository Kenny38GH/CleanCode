#include "../lib/Flock.hpp"

Flock::~Flock() { std::cout << _boids.size() << std::endl; }

void Flock::update(const double &dT) {
  for (auto &boid : _boids) {
    boid.update(dT);
  }
}

void Flock::render() {
  for (auto &boid : _boids) {
    boid.render();
  }
}

void Flock::add_boid(const glm::vec3 &pos) { _boids.push_back(Boid(pos)); }