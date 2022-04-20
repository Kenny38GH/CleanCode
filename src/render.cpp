#include "../lib/render.hpp"

void render_circle(p6::Context &ctx, p6::Center &center, float radius) {
  ctx.fill = {1, 1, 0, 1};
  ctx.circle(center, p6::Radius{radius});
}