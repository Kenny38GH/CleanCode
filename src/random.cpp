#include "../lib/random.hpp"

float random_num(int inf_bound, int sup_bound) {
  return rand() % sup_bound + inf_bound;
}

int custom_random_num(std::vector<float> finite_space) {
  float k = primary_rand();
  float x = 0;
  for (size_t i = 0; i < finite_space.size(); i++) {
    x += finite_space[i];
    if (x >= k) {
      return i;
    }
  }
}

float accidental_phenomena(float lambda) {
  return (-1 / lambda) * log(primary_rand());
}