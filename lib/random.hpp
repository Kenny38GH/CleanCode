#pragma once
#include <cassert>
#include <cstdlib>
#include <functional>
#include <glm/glm.hpp>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#define RAND_MAX 2147483647

inline float primary_rand() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  return (dis(gen));
}

inline int heads_or_tails() {
  srand((unsigned)time(NULL));
  return primary_rand() > 0.5 ? 1 : -1;
}

int number_with_random_law(int number_of_probabilities);
int number_with_custom_law(std::vector<float> custom_law);

float accidental_phenomena(float lambda);
float bernoulli(float p);
unsigned int geo_sequence(float p);
float binomial_law(unsigned int n, unsigned int k, float p);
inline unsigned int factorial(unsigned int n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int poissrnd(float mean);
