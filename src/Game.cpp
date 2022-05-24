#include "../lib/Game.hpp"
void Game::activate_easy_mode(Flock *flock, float max_speed) {

  int nb = 15 + static_cast<int>(loiBeta(2.f, 5.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * (number_with_random_law(3) + 1);
    float pos_x = primary_rand() * heads_or_tails();
    float pos_y = primary_rand() * heads_or_tails();
    flock->add_boid(glm::vec2(pos_x, pos_y), speedo);
  }
}

void Game::activate_normal_mode(Flock *flock, float max_speed) {
  int nb = 15 + static_cast<int>(loiBeta(2.f, 2.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * (number_with_random_law(3) + 1);
    flock->add_boid(glm::vec2(primary_rand() * heads_or_tails(),
                              primary_rand() * heads_or_tails()),
                    speedo);
  }
}

void Game::activate_hard_mode(Flock *flock, float max_speed) {
  int nb = 20 + static_cast<int>(loiBeta(5.f, 1.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * (number_with_random_law(3) + 1);
    flock->add_boid(glm::vec2(primary_rand() * heads_or_tails(),
                              primary_rand() * heads_or_tails()),
                    speedo);
  }
}

void Game::activate_cheat_mode(Flock *flock, float max_speed) {

  for (int i = 0; i < 1; i++) {
    float speedo = max_speed;
    float pos_x = 0.f;
    float pos_y = -1.f;
    flock->add_boid(glm::vec2(pos_x, pos_y), speedo);
  }
}

void Game::change_enclos_pos(glm::vec2 &enclos) {
  enclos = glm::vec2(primary_rand() * heads_or_tails(),
                     primary_rand() * heads_or_tails());
  while (enclos.x < -0.7f && enclos.x > 0.7f) {
    while (enclos.y < -0.7f && enclos.y > 0.7f) {
      enclos = glm::vec2(primary_rand() * heads_or_tails(),
                         primary_rand() * heads_or_tails());
    }
  }
}