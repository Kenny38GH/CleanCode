#pragma once
#include <glm/glm.hpp>

void display_sheep(const glm::vec3 &position, const glm::vec3 &velocity,
                   const int &size, const int cb);

void display_stable(const glm::vec3 &position, const int &size);

void display_grass();
void display_border();