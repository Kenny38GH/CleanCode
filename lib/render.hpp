#ifndef RENDER_HPP
#define RENDER_HPP

#include "vector.hpp"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <math.h>

void initGL();

void renderCircle(Vector center, Vector color, int size);
void renderRect(Vector center, Vector color, int h, int w);


#endif