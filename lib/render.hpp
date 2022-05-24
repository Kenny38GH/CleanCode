#pragma once
#include <iostream>
#include <p6/p6.h>

void render_circle(p6::Context &ctx, p6::Center &center, float &radius);
void display_sheep(p6::Context &ctx, glm::vec2 &position, glm::vec2 &velocity,
                   float &size, float &saturation);
void display_doggo(p6::Context &ctx, glm::vec2 &position, glm::vec2 &velocity,
                   float &size);

void display_grass(p6::Context &ctx);
void display_border(p6::Context &ctx);
void display_enclos(p6::Context &ctx, glm::vec2 enclos);