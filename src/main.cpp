
#include "../lib/Boid.hpp"
#include "../lib/random.hpp"
#include "../lib/render.hpp"
#include <iostream>
#include <list>
#include <p6/p6.h>

int main() {
  auto ctx = p6::Context{{1280, 720, "BOIDS"}};
  ctx.time_perceived_as_constant_delta_time(60.f);
  auto radius = 0.05f;
  std::list<Boid *> objects;
  float time, dT, x, y = 0.f;

  ctx.imgui = [&]() {
    // Show a simple window
    ImGui::Begin("Parameters");
    ImGui::SliderFloat("Square size", &radius, 0.f, 1.f);
    ImGui::InputFloat("Time", &time);
    ImGui::InputFloat("dT", &dT);
    ImGui::InputFloat("x", &x);
    ImGui::InputFloat("y", &y);
    ImGui::End();
    // Show the official ImGui demo window
    // It is very useful to discover all the widgets available in ImGui
    ImGui::ShowDemoWindow();
  };
  ctx.mouse_pressed = [&](p6::MouseButton) {
    Boid *nb = new Boid(ctx.mouse());
    objects.push_back(nb);
    std::cout << "Mouse Pressed" << std::endl;
  };
  ctx.update = [&]() {
    x = ctx.mouse().x;
    y = ctx.mouse().y;
    ctx.background({0, 1, 0.3, 0});

    /* PHYSIQUE LOOP*/
    time = ctx.time();
    dT = ctx.delta_time();

    glm::vec2 point_to_seek = ctx.mouse();

    for (Boid *physc : objects) {
      // Movement update and collision check
      physc->seek(point_to_seek);
      physc->update(dT);
    }

    /* RENDERING LOOP */

    for (Boid *rendc : objects) {
      auto center = p6::Center(rendc->_position);
      render_circle(ctx, center, radius);
    };
  };

  ctx.start();

  /* ZONE DE TEST DES FONCTIONS RANDOM */
  std::cout << "/* ZONE DE TEST DES FONCTIONS RANDOM */" << std::endl;

  std::cout << "A random number: " << primary_rand() << std::endl;
  std::cout << "Res of heads or tails (0 or 1)..: " << heads_or_tails()
            << std::endl;
  std::cout << "Accidental event (parameter fixed): " << accidental_phenomena(3)
            << std::endl;
  std::cout << "Random value from random law: " << number_with_random_law(9)
            << std::endl;

  std::vector<float> dumb_law = {0.2, 0.5, 0.3};
  std::cout << "Custom random value: " << number_with_custom_law(dumb_law)
            << std::endl;
  std::cout << "Bernouilli law res :" << bernoulli(0.9f) << std::endl;
  std::cout << "Nb de try jusqu'à avoir un succès | Geo sequence res: "
            << geo_sequence(0.99f) << std::endl;
  std::cout << "Proba d'avoir k succès en n parties avec une probabilité de "
               "succès p | Binomial law res : "
            << binomial_law(10, 8, 0.9f) << std::endl;
  std::cout << "Poisson law res: " << poissrnd(0.5) << std::endl;
};
