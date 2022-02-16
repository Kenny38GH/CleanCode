#ifndef BALL_HPP
#define BALL_HPP

#include "vector.hpp"
#include "render.hpp"


class Ball{
private:
    int size;
    Vector color;
    Vector poz;
    Vector vitess;
    Vector accel;
    
public:
    Ball(int size, Vector color, Vector poz);
    ~Ball();
    void update(float dT);
    bool collision(Ball ball);
    bool collision();
    void render();
};

#endif