#ifndef RENDER_HPP
#define RENDER_HPP

#include "vector.hpp"
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

void initGL();

void renderCircle(Vector center, Vector color, int size);
void renderRect(Vector center, Vector color, int h, int w);
void renderTriangle(glm::vec3 center, glm::vec3 dir, float size);

#endif