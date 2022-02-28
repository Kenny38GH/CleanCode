#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

void initGL();

void renderCircle(const glm::vec3 &center, const glm::vec3 &color, const int &size);
void renderRect(const glm::vec3 &center, const glm::vec3 &color, const int &h, const int &w);
void renderTriangle(const glm::vec3 &center, const glm::vec3 &dir, const float &size);
