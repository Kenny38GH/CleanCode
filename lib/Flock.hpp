#pragma once 

#include "Boid.hpp"
#include <vector>

class Flock {
private:
    std::vector<Boid*> _boids;

public:

    Flock() = default;
    ~Flock()= default;

    void update(const Uint32 &dT);
    void render();
    void add_boid(Boid* &b);

};