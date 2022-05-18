#include "../includes/Boid.hpp"
#include "../includes/Flock.hpp"
#include "../includes/render_assets.hpp"
#include "../includes/render_shape.hpp"
#include <iostream>
#include <list>

int main() {

  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow("BOIDS", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 1000, 1000,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    } else {

      SDL_GLContext glcont = SDL_GL_CreateContext(window);
      bool quit = false;
      Uint32 lastUpdate = SDL_GetTicks();
      SDL_Event e;
      SDL_EventType last_event;

      Flock flock;

      while (!quit) {

        int x, y;
        SDL_GetMouseState(&x, &y);

        while (SDL_PollEvent(&e) != 0) {
          switch (e.type) {
          case SDL_QUIT:
            quit = true;
            break;
          case SDL_MOUSEBUTTONDOWN:
            flock.add_boid(glm::vec3(x, y, 0));
            break;
          default:
            break;
          }
        }
        /* PHYSIQUE LOOP */

        Uint32 current = SDL_GetTicks();

        float dT = static_cast<float>(current - lastUpdate) / 1000.0f;
        flock.update(dT);

        lastUpdate = current;

        /* RENDERING LOOP */

        init_gl();
        display_grass();
        display_border();
        flock.render();

        SDL_GL_SwapWindow(window);
      }

      // Destroy context
      SDL_GL_DeleteContext(glcont);
    }
  }

  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}
