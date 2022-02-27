#include "../lib/render.hpp"

void initGL() {
  glClearColor(0.1, 0.1, 0.1, 0.);
  glViewport(0, 0, 1000, 1000);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1000, 1000, 0.0f, -1.f, 1.f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void renderCircle(Vector center, Vector color, int size) {

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(color.x, color.y, color.z);
  for (int i = 0; i < 20; i++) {
    float theta =
        2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(20);
    float x = size * cosf(theta);
    float y = size * sinf(theta);
    glVertex2f(center.x + x, center.y + y);
  }
  glEnd();
}

void renderRect(Vector center, Vector color, int h, int w) {

  glBegin(GL_LINE_STRIP);
  glColor3f(color.x, color.y, color.z);
  glVertex2f(center.x + h, center.y + w);
  glVertex2f(center.x + h, center.y - w);
  glVertex2f(center.x - h, center.y - w);
  glVertex2f(center.x - h, center.y + w);
  glEnd();
}

void renderTriangle(glm::vec3 center, glm::vec3 dir, float size) {

  glm::vec3 dir_crossed = glm::normalize(glm::cross(-dir, glm::vec3(0,0,1)));
  dir = glm::normalize(dir);

  glm::vec3 pt1 = center + dir * size;
  glm::vec3 pt2 = center - dir + dir_crossed * size * 0.5f;
  glm::vec3 pt3 = center - dir - dir_crossed * size * 0.5f; 

  glBegin(GL_TRIANGLES);
  glColor3f(1, 1, 1);
  glVertex2f(pt1.x, pt1.y);
  glColor3f(1, 0.5, 0);
  glVertex2f(pt2.x, pt2.y);
  glColor3f(0.5, 1, 0);
  glVertex2f(pt3.x, pt3.y);
  glEnd();
}