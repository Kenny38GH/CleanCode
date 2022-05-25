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

  ctx.fill = {saturation + 2.f * saturation, saturation + 2.f * saturation,
              saturation + 2.f * saturation};

  center = p6::Center(position);
  ctx.circle(center, p6::Radius{size});

  center = p6::Center(position - nvelo * 0.03f);
  ctx.circle(center, p6::Radius{size});
}

void display_doggo(p6::Context &ctx, glm::vec2 &position, glm::vec2 &velocity,
                   float &size) {
  ctx.use_fill = true;
  ctx.use_stroke = false;
  ctx.fill = {1, 0.5f, 0.5f};
  glm::vec2 nvelo = glm::normalize(velocity);
  auto center = p6::Center(position + nvelo * 0.03f);
  ctx.circle(center, p6::Radius{size});

  ctx.fill = {0.f, 0.f, 0.f};
  center = p6::Center(position + nvelo * 0.015f);
  ctx.circle(center, p6::Radius{size});

  ctx.fill = {1, 1.f, 1.f};
  center = p6::Center(position);
  ctx.circle(center, p6::Radius{size});

  ctx.fill = {.8f, .4f, .2f};
  center = p6::Center(position - nvelo * 0.015f);
  ctx.circle(center, p6::Radius{size});

  ctx.fill = {.5f, .2f, .1f};
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
  ctx.square(center, p6::Radius{0.98f});
}

void display_enclos(p6::Context &ctx, glm::vec2 enclos) {
  ctx.use_stroke = true;
  ctx.use_fill = true;
  ctx.stroke = {0.f, 0.f, 0.f};
  auto center = p6::Center(enclos);
  ctx.square(center, p6::Radius{0.1f});
  ctx.fill = {191.f / 255.f, 40.f / 255.f, 13.f / 255.f};
  center = p6::Center(glm::vec2(enclos.x, enclos.y - 0.05));
  ctx.rectangle(center, p6::Radii{0.1f, 0.05f});
  ctx.fill = p6::NamedColor::White;
  ctx.text_size = 0.02f;
  auto topleftcorner =
      p6::TopLeftCorner(glm::vec2(enclos.x - 0.12f, enclos.y - 0.1));
  ctx.text(u"Enclos", topleftcorner);
}