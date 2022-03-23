#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <iostream>

void begin_opengl_frame();

void render_circle(const glm::vec3 &center, const glm::vec3 &color, const int &size);
void render_rect(const glm::vec3 &center, const glm::vec3 &color, const int &h, const int &w);
void render_triangle(const glm::vec3 &center, const glm::vec3 &dir, const float &size);
