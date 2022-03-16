#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>

float random_num_uniform_distrib(float inf_bound, float sup_bound);

inline float primary_rand() {
  srand((unsigned)time(NULL));
  return (float)rand() / RAND_MAX;
}

inline int heads_or_tails() {
  srand((unsigned)time(NULL));
  return primary_rand() > 0.5 ? 1 : 0;
}