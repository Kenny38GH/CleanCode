#include "../lib/random.hpp"

int number_with_random_law(int number_of_probabilities) {
  std::vector<float> space;
  float sum = 0;
  for (size_t i = 0; i < number_of_probabilities; i++) {
    float random_num = primary_rand();
    sum += random_num;
    space.push_back(random_num);
  }
  for (auto &num : space) {
    num = num / sum;
  }
  float k = primary_rand();
  float x = 0;
  for (int i = 0; i < space.size(); i++) {
    x += space[i];
    if (x >= k) {
      return i;
    }
  }
}

int number_with_custom_law(std::vector<float> custom_law) {
  float secure_one = 0;
  for (auto &n : custom_law) {
    secure_one += n;
  }

  if (secure_one != 1.0) {
    assert("Your law is not law wsshh !");
  }

  float k = primary_rand();
  float x = 0;
  for (int i = 0; i < custom_law.size(); i++) {
    x += custom_law[i];
    if (x >= k) {
      return i;
    }
  }
}

float accidental_phenomena(float lambda) {
  return (-1 / lambda) * log(primary_rand());
}

float bernoulli(float p) {
  float r = primary_rand();
  unsigned int br = 0;
  if (r >= p)
    br = 1;
  return br;
}

unsigned int geo_sequence(float p) {
  bool isFinish = false;
  unsigned int nb_try = 0;
  while (isFinish == false) {
    float r = primary_rand();
    nb_try += 1;
    if (r > p) {
      isFinish = true;
    }
  }
  return nb_try;
}

float binomial_law(unsigned int n, unsigned int k, float p) {
  float Ckn = factorial(n) / (factorial(k) * factorial(n - k));
  return Ckn * pow(p, k) * pow(1 - p, n - k);
}

int poissrnd(float mean) {
  std::cout << "Still not working --> ";
  float r = 0.f;
  float x = 0.f;
  float m = 0.f;
  float pi = 3.1415926535897932384626433832795;
  float sqrt_mean = sqrt(mean);
  float log_mean = log(mean);
  float g_x = 0.f;
  float f_m = 0.f;

  while (drand48() > r) {
    while (x < 0) {
      x = mean + sqrt_mean * tan(pi * (drand48() - 1 / 2.0));
    }
    g_x = sqrt_mean / (pi * ((x - mean) * (x - mean) + mean));
    m = floor(x);
    f_m = exp(m * log_mean - mean - lgamma(m + 1));
    r = f_m / g_x / 2.4;
  };
  return (int)m;
}