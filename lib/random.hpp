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
  std::random_device
      rd; // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<> dis(0.0, 1.0);
  return dis(gen);
}

inline int heads_or_tails() { return primary_rand() > 0.5 ? 1 : -1; }

int number_with_random_law(int number_of_probabilities);
int number_with_custom_law(std::vector<float> custom_law);

float accidental_phenomena(float lambda);
float bernoulli(float p);
unsigned int geo_sequence(float p);
float binomial_law(unsigned int n, unsigned int k, float p);
inline unsigned int factorial(unsigned int n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
};
float loiBeta(float n, float m);
float loiBetaDecentree(float n, float m, float a, float b);
int poissrnd(float mean);
