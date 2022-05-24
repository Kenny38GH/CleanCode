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
  void activate_cheat_mode(Flock *flock, float max_speed);
  void change_enclos_pos(glm::vec2 &enclos);
};
