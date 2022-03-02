#include "../lib/Flock.hpp"

void Flock::update(const Uint32 &dT) {
    for(int b_nb = 0; b_nb < _boids.size(); b_nb++) {
        _boids[b_nb]->update(dT);
    }
}

void Flock::render() {
    for(int b_nb = 0; b_nb < _boids.size(); b_nb++) {
        _boids[b_nb]->render();
    }
}

void Flock::add_boid(Boid* &b) {
    _boids.push_back(b);
}