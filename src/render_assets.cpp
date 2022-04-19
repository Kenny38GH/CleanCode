#include "../includes/render_assets.hpp"
#include "../includes/render_shape.hpp"

void display_sheep(const glm::vec3 &position, const glm::vec3 &velocity,
                   const int &size) {
  // glm::vec3 nspeed = glm::normalize(velocity);
  render_circle(position + velocity, glm::vec3(1.f, 0.5f, 0.5f), size);
  render_circle(position + velocity * 0.5f, glm::vec3(1.f), size);
  render_circle(position, glm::vec3(1.f), size);
  render_circle(position - velocity, glm::vec3(1.f), size);
}

void display_grass() {
  render_circle(glm::vec3(500, 500, 0), glm::vec3(0.1f, 0.75f, 0.1f), 800);
  render_circle(glm::vec3(1000, 500, 0), glm::vec3(0.1f, 0.9f, 0.2f), 700);
  render_circle(glm::vec3(100, 0, 0), glm::vec3(0.1f, 1.f, 0.2f), 200);
}

void display_border() {
  render_rect(glm::vec3(505, 505, 0), glm::vec3(0.4f, 0.1f, 0.1f), 930, 930);
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 10; i++) {
      render_circle(glm::vec3(40 + i * 100, 40 + j * 930, 0),
                    glm::vec3(0.5f, 0.2f, 0.2f), 4);
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 10; i++) {
      render_circle(glm::vec3(40 + j * 930, 40 + i * 100, 0),
                    glm::vec3(0.5f, 0.2f, 0.2f), 4);
    }
  }
}

// void display_stable(const glm::vec3 &position, const int &size) {}