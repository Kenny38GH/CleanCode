#include "../includes/Flock.hpp"

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

const std::vector<Boid*> Flock::in_fov_of(const Boid &boid) {
  std::vector<Boid*> return_vector;
  for( auto &b : _boids;) {
    if(boid.sees(b)) {
      return_vector.push_back(b);
    }
  }
  return return_vector;
}