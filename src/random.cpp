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