#include "../lib/render.hpp"

void initGL(){
    glClearColor(0.,0.,0.,0.);
    glViewport(0,0,500,500);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 500, 500, 0.0f, -1.f, 1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void renderCircle(Vector center, Vector color, int size){

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(color.x, color.y, color.z);
        for(int i=0; i<20; i++){
            float theta = 2.0f * 3.1415926f * static_cast<float>(i) / static_cast<float>(20) ;
            float x = size * cosf(theta);
            float y = size * sinf(theta);
            glVertex2f(center.x + x, center.y + y);
        }
    glEnd();
}

void renderRect(Vector center, Vector color, int h, int w){

    glBegin(GL_LINE_STRIP);
        glColor3f(color.x, color.y, color.z);
        glVertex2f(center.x + h, center.y + w);
        glVertex2f(center.x + h, center.y - w);
        glVertex2f(center.x - h, center.y - w);
        glVertex2f(center.x - h, center.y + w);
    glEnd();
}