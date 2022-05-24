#include "../lib/render.hpp"

void render_circle(p6::Context &ctx, p6::Center &center, float &radius) {
  ctx.fill = {1, 1, 0, 1};
  ctx.circle(center, p6::Radius{radius});
}

void display_sheep(p6::Context &ctx, glm::vec2 &position, glm::vec2 &velocity,
                   float &size, float &saturation) {

  ctx.use_fill = true;
  ctx.use_stroke = false;
  ctx.fill = {1, 0.7f, 0.7f};
  glm::vec2 nvelo = glm::normalize(velocity);
  auto center = p6::Center(position + nvelo * 0.03f);
  ctx.circle(center, p6::Radius{size});
  ctx.fill = {0, 0, 0};
  center = p6::Center(position + nvelo * 0.06f);
  ctx.circle(center, p6::Radius{size / 4});

  ctx.fill = {saturation + 0.7f, saturation + 0.7f, saturation + 0.7f};

  center = p6::Center(position);
  ctx.circle(center, p6::Radius{size});

  center = p6::Center(position - nvelo * 0.03f);
  ctx.circle(center, p6::Radius{size});
}

void display_grass(p6::Context &ctx) {
  ctx.use_fill = true;
  ctx.fill = {0.1f, 0.9f, 0.2f};
  ctx.use_stroke = false;
  auto center = p6::Center(glm::vec2(1, 0));
  ctx.circle(center, p6::Radius{1.4});

  ctx.fill = {0.1f, 1.f, 0.2f};
  center = p6::Center(glm::vec2(-0.9, 1));
  ctx.circle(center, p6::Radius{0.5});
}

void display_border(p6::Context &ctx) {
  ctx.use_fill = false;
  ctx.use_stroke = true;
  ctx.stroke = {0.f, 0.f, 0.f};
  auto center = p6::Center(glm::vec2(0, 0));
  ctx.square(center, p6::Radius{0.95f});
}