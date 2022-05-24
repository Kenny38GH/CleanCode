#pragma once
#include "Flock.hpp"
#include "random.hpp"

class Game {
private:
  /* data */
public:
  Game() = default;
  ~Game() = default;
  void activate_easy_mode(Flock *flock, float max_speed);
  void activate_normal_mode(Flock *flock, float max_speed);
  void activate_hard_mode(Flock *flock, float max_speed);
};
