#include "../lib/Flock.hpp"

Flock::~Flock() { std::cout << _boids.size() << std::endl; }

void Flock::update(const double &dT, const glm::vec3 &point_to_seek) {
  for (auto &boid : _boids) {
    boid.seek(point_to_seek);
    boid.update(dT);
  }
}

void Flock::render() {
  for (auto &boid : _boids) {
    boid.render();
  }
}

void Flock::add_boid(const glm::vec3 &pos) { _boids.push_back(Boid(pos)); }