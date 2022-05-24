#include "../lib/Game.hpp"
void Game::activate_easy_mode(Flock *flock, float max_speed) {

  int nb = 15 + static_cast<int>(loiBeta(2.f, 5.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * number_with_random_law(3);

    flock->add_boid(glm::vec2(primary_rand() * heads_or_tails(),
                              primary_rand() * heads_or_tails()),
                    speedo);
  }
}

void Game::activate_normal_mode(Flock *flock, float max_speed) {
  int nb = 15 + static_cast<int>(loiBeta(2.f, 2.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * number_with_random_law(3);
    flock->add_boid(glm::vec2(primary_rand() * heads_or_tails(),
                              primary_rand() * heads_or_tails()),
                    speedo);
  }
}

void Game::activate_hard_mode(Flock *flock, float max_speed) {
  int nb = 20 + static_cast<int>(loiBeta(5.f, 1.f) * 10);
  for (int i = 0; i < nb; i++) {
    float speedo = max_speed * number_with_random_law(3);
    flock->add_boid(glm::vec2(primary_rand() * heads_or_tails(),
                              primary_rand() * heads_or_tails()),
                    speedo);
  }
}