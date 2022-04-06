#include "../includes/render.hpp"

void init_gl() {
  glClearColor(0.1f, 0.1f, 0.1f, 0.f);
  glViewport(0, 0, 1000, 1000);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1000, 1000, 0.0f, -1.f, 1.f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void render_circle(const glm::vec3 &center, const glm::vec3 &color,
                   const int &size) {

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(color.x, color.y, color.z);
  for (int i = 0; i < 20; i++) {
    float theta =
        2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(20);
    float x = static_cast<float>(size) * cosf(theta);
    float y = static_cast<float>(size) * sinf(theta);
    glVertex2f(center.x + x, center.y + y);
  }
  glEnd();
}

void render_rect(const glm::vec3 &center, const glm::vec3 &color, const int &h,
                 const int &w) {

  glBegin(GL_LINE_STRIP);
  glColor3f(color.x, color.y, color.z);
  glVertex2f(center.x + static_cast<float>(h),
             center.y + static_cast<float>(w));
  glVertex2f(center.x + static_cast<float>(h),
             center.y - static_cast<float>(w));
  glVertex2f(center.x - static_cast<float>(h),
             center.y - static_cast<float>(w));
  glVertex2f(center.x - static_cast<float>(h),
             center.y + static_cast<float>(w));
  glEnd();
}

void render_triangle(const glm::vec3 &center, const glm::vec3 &dir,
                     const float &size) {

  glm::vec3 dir_crossed = glm::normalize(glm::cross(-dir, glm::vec3(0, 0, 1)));
  glm::vec3 dir_normalized = glm::normalize(dir);

  glm::vec3 pt1 = center + dir_normalized * size;
  glm::vec3 pt2 = center - dir_normalized + dir_crossed * size * 0.5f;
  glm::vec3 pt3 = center - dir_normalized - dir_crossed * size * 0.5f;

  glBegin(GL_TRIANGLES);
  glColor3f(1, 1, 1);
  glVertex2f(pt1.x, pt1.y);
  glColor3f(1, 0.5, 0);
  glVertex2f(pt2.x, pt2.y);
  glColor3f(0.5, 1, 0);
  glVertex2f(pt3.x, pt3.y);
  glEnd();
}