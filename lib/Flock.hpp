#pragma once 

#include "Boid.hpp"
#include <vector>

class Flock {
private:
    std::vector<Boid*> _boids;

public:

    Flock() = default;
    ~Flock()= default;

    inline void update(const Uint32 &dT) {for(Boid* b : _boids) b->update(dT);}
};