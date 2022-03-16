#include "../lib/random.hpp"

float random_num_uniform_distrib(float inf_bound, float sup_bound) {
  std::random_device rd;  // non-deterministic generator
  std::mt19937 gen(rd()); // to seed mersenne twister.
  std::uniform_int_distribution<> dist(
      inf_bound, sup_bound); // distribute results between inf_bound and
                             // sup_bound inclusive.
  std::cout << dist(gen);    // pass the generator to the distribution.
  std::cout << std::endl;
}
