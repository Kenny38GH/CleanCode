#include "../lib/Boid.hpp"
#include "../lib/random.hpp"
#include "../lib/render.hpp"
#include <iostream>
#include <list>

int main(int argc, char *argv[]) {

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

      std::list<Boid *> objects;

      while (!quit) {

        Uint64 start = SDL_GetPerformanceCounter();
        int x, y;
        SDL_GetMouseState(&x, &y);

        while (SDL_PollEvent(&e) != 0) {
          switch (e.type) {
          case SDL_QUIT:
            quit = true;
            break;
          case SDL_MOUSEBUTTONDOWN:
            last_event = SDL_MOUSEBUTTONDOWN;
            break;
          case SDL_MOUSEBUTTONUP:
            last_event = SDL_MOUSEBUTTONUP;
            break;
          default:
            break;
          }
        }

        if (last_event == SDL_MOUSEBUTTONDOWN) {
          Boid *nb = new Boid(glm::vec3(x, y, 0));
          objects.push_back(nb);
        }

        Uint64 event = SDL_GetPerformanceCounter();

        /* PHYSIQUE LOOP*/

        Uint32 current = SDL_GetTicks();
        Uint32 time = SDL_GetTicks();

        float dT = (current - lastUpdate) / 1000.0f;
        glm::vec3 point_to_seek =
            glm::vec3(glm::vec3(500 + 200 * glm::cos(time / 1000.),
                                500 + 200 * glm::sin(time / 1000.), 0));
        point_to_seek = glm::vec3(x, y, 0);

        for (Boid *physc : objects) {
          // Movement update and collision check
          // physc->collision();
          physc->seek(point_to_seek);
          physc->update(dT);
        }
        lastUpdate = current;
        Uint64 phys = SDL_GetPerformanceCounter();

        /* RENDERING LOOP */

        init_gl();

        render_circle(point_to_seek, glm::vec3(1, 0, 0), 3);

        for (Boid *rendc : objects) {
          rendc->render();
        }
        SDL_GL_SwapWindow(window);

        Uint64 end = SDL_GetPerformanceCounter();
      }

      std::cout << "Number of boids: " << objects.size() << std::endl;
      //
      // Destroy context
      SDL_GL_DeleteContext(glcont);
    }
    /* ZONE DE TEST DES FONCTIONS RANDOM */
    std::cout << "A random number: " << primary_rand() << std::endl;
    std::cout << "Res of heads or tails (0 or 1)..: " << heads_or_tails()
              << std::endl;
    std::cout << "Accidental event (parameter fixed): "
              << accidental_phenomena(3) << std::endl;
    std::cout << "Random value from random law: " << number_with_random_law(9)
              << std::endl;

    std::vector<float> dumb_law = {0.2, 0.5, 0.3};
    std::cout << "Custom random value: " << number_with_custom_law(dumb_law)
              << std::endl;
    std::cout << "Bernouilli law res :" << bernoulli(0.9) << std::endl;
    std::cout << "Nb de try jusqu'à avoir un succès | Geo sequence res: "
              << geo_sequence(0.99f) << std::endl;
    std::cout << "Proba d'avoir k succès en n parties avec une probabilité de "
                 "succès p | Binomial law res : "
              << binomial_law(10, 8, 0.9f) << std::endl;
    std::cout << "Poisson law res: " << poissrnd(0.5) << std::endl;
  }
  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();
  return 0;
}