#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>

inline float primary_rand() {
  srand((unsigned)time(NULL));
  return (float)rand() / RAND_MAX;
}

inline int heads_or_tails() {
  srand((unsigned)time(NULL));
  return primary_rand() > 0.5 ? 1 : 0;
}

int number_with_random_law(int number_of_probabilities);
int number_with_custom_law(std::vector<float> custom_law);

float accidental_phenomena(float lambda);
