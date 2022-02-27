#ifndef BALL_HPP
#define BALL_HPP

#include "render.hpp"
#include "vector.hpp"

class Ball {
private:
  float size;
  Vector color;
  Vector poz;
  Vector vitess;
  Vector accel;

public:
  Ball(float size, Vector color, Vector poz);
  ~Ball();
  void update(float dT);
  bool collision();
  void render();
};

#endif