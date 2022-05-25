#include "../lib/Boid.hpp"
#include "../lib/Flock.hpp"
#include "../lib/Game.hpp"
#include "../lib/random.hpp"
#include "../lib/render.hpp"
#include <iostream>
#include <list>
#include <p6/p6.h>
#include <string>

int main() {
  auto ctx = p6::Context{{1000, 1000, "MOUMOUT PARTY"}};
  ctx.time_perceived_as_constant_delta_time(60.f);
  auto radius = 0.03f;
  float max_speed = 0.1f;
  Flock flock;
  Game game;
  float time, dT, x, y = 0.f;
  bool time_has_changed = false;
  float ImGuiWidth = 500;
  float ImGuiHight = 200;
  int nb_moutmout = 0;
  float timeofmylife = 0.f;
  bool mode_choosen = false;
  glm::vec2 target_dog = glm::vec2(0);
  glm::vec2 enclos = glm::vec2(primary_rand() * heads_or_tails(),
                               primary_rand() * heads_or_tails());

  int it_is_time_to_say_goodbye = geo_sequence(0.99f);
  bool game_has_been_played = false;
  bool time_is_freezed = false;

  ctx.imgui = [&]() {
    // Show a simple window

    ImGui::Begin("Menu des paramètres");
    ImGui::SetWindowSize(ImVec2((float)ImGuiWidth, (float)ImGuiHight));
    ImGui::StyleColorsLight();

    if (ImGui::Button("Facile") && mode_choosen == false) {

      enclos = glm::vec2(primary_rand() * heads_or_tails(),
                         primary_rand() * heads_or_tails());
      while (enclos.x < -0.7f && enclos.x > 0.7f) {
        while (enclos.y < -0.7f && enclos.y > 0.7f) {
          enclos = glm::vec2(primary_rand() * heads_or_tails(),
                             primary_rand() * heads_or_tails());
        }
      }
      game.activate_easy_mode(&flock, max_speed);
      it_is_time_to_say_goodbye = 30 * 100;
      mode_choosen = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Normal") && mode_choosen == false) {
      enclos = glm::vec2(primary_rand() * heads_or_tails(),
                         primary_rand() * heads_or_tails());
      while (enclos.x < -0.7f && enclos.x > 0.7f) {
        while (enclos.y < -0.7f && enclos.y > 0.7f) {
          enclos = glm::vec2(primary_rand() * heads_or_tails(),
                             primary_rand() * heads_or_tails());
        }
      }
      game.activate_normal_mode(&flock, max_speed);
      it_is_time_to_say_goodbye = it_is_time_to_say_goodbye * 2;
      mode_choosen = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Difficile") && mode_choosen == false) {
      enclos = glm::vec2(primary_rand() * heads_or_tails(),
                         primary_rand() * heads_or_tails());
      while (enclos.x < -0.7f && enclos.x > 0.7f) {
        while (enclos.y < -0.7f && enclos.y > 0.7f) {
          enclos = glm::vec2(primary_rand() * heads_or_tails(),
                             primary_rand() * heads_or_tails());
        }
      }
      game.activate_hard_mode(&flock, max_speed);
      it_is_time_to_say_goodbye = it_is_time_to_say_goodbye;
      mode_choosen = true;
    }
    ImGui::SameLine();
    if (ImGui::Button("Triche") && mode_choosen == false) {
      enclos = glm::vec2(0.9, -0.9);
      game.activate_cheat_mode(&flock, max_speed);
      it_is_time_to_say_goodbye = 60000;
      mode_choosen = true;
    }
    ImGui::InputInt("So Long?", &it_is_time_to_say_goodbye);
    ImGui::SliderFloat("Taille des moutons", &radius, 0.f, 1.f);
    ImGui::SliderFloat("Vitesse MAXIMALE", &max_speed, 0.1f, 0.3f);
    if (ImGui::Button("Démarrer la partie !") && mode_choosen == true) {
      if (ctx.is_paused()) {
        ctx.resume();
      }
      time_is_freezed = false;
      ctx.mouse_pressed = [&](p6::MouseButton) {
        // flock.add_boid(ctx.mouse(), max_speed);
        target_dog = glm::vec2(ctx.mouse());
      };
      ctx.update = [&]() {
        x = ctx.mouse().x;
        y = ctx.mouse().y;
        ctx.background({0.1f, 0.75f, 0.1f, 0});

        /* PHYSIQUE LOOP*/
        time = ctx.time();
        dT = ctx.delta_time();

        flock.update(dT, target_dog, enclos);
        nb_moutmout = flock.get_size();

        /* RENDERING LOOP */
        display_grass(ctx);
        display_border(ctx);
        display_enclos(ctx, enclos);

        flock.render(ctx, radius);
        ctx.fill = p6::NamedColor::White;
        ctx.text_size = 0.04f;
        std::u16string moutmout_restant = to_u16string(nb_moutmout);
        auto topleftcorner = p6::TopLeftCorner(glm::vec2(-0.9f, 0.9f));
        ctx.text(moutmout_restant, topleftcorner);
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.75f, 0.88f));
        ctx.text_size = 0.03f;
        ctx.text(u"moutmouts", topleftcorner);

        game_has_been_played = true;

        // CHANGE LA PLACE DE L'ENCLOS TT LES X SECONDES
        if (int(time) % it_is_time_to_say_goodbye == 0 &&
            time_has_changed == false) {
          enclos = glm::vec2(primary_rand() * heads_or_tails(),
                             primary_rand() * heads_or_tails());
          while (enclos.x < -0.7f && enclos.x > 0.7f) {
            while (enclos.y < -0.7f && enclos.y > 0.7f) {
              enclos = glm::vec2(primary_rand() * heads_or_tails(),
                                 primary_rand() * heads_or_tails());
            }
          }
          time_has_changed = true;
        }

        if (int(time) % it_is_time_to_say_goodbye != 0 &&
            time_has_changed == true) {
          time_has_changed = false;
        }
      };
    }
    ImGui::SameLine();
    if (ImGui::Button("Redemarrer la partie!") && mode_choosen == true) {
      game_has_been_played = false;
      it_is_time_to_say_goodbye = geo_sequence(0.99f);
      flock.reset();
      target_dog = glm::vec2(0);
      mode_choosen = false;
      ctx.update = [&]() {
        x = ctx.mouse().x;
        y = ctx.mouse().y;
        ctx.background({0.1f, 0.75f, 0.1f, 0});

        /* PHYSIQUE LOOP*/
        time = ctx.time();
        dT = ctx.delta_time();

        flock.update(dT, target_dog, enclos);

        /* RENDERING LOOP */
        display_grass(ctx);
        display_border(ctx);
        ctx.fill = p6::NamedColor::White;
        ctx.text_size = 0.04f;
        auto topleftcorner = p6::TopLeftCorner(glm::vec2(-0.7f, 0.1f));
        ctx.text(u"Choisi tes options", topleftcorner);
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.1f, -0.0f));
        ctx.text(u"et", topleftcorner);
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.7f, -0.1f));
        ctx.text(u"Demarre la partie !", topleftcorner);
        glm::vec2 enclos = glm::vec2(primary_rand() * heads_or_tails(),
                                     primary_rand() * heads_or_tails());
      };
    }

    if (nb_moutmout == 0 && game_has_been_played == true &&
        mode_choosen == true) {

      if (time_is_freezed == false) {
        timeofmylife = ctx.time();
        time_is_freezed = true;
      }
      target_dog = glm::vec2(0);
      ctx.update = [&]() {
        x = ctx.mouse().x;
        y = ctx.mouse().y;
        ctx.background({0.1f, 0.75f, 0.1f, 0});

        /* PHYSIQUE LOOP*/
        time = ctx.time();
        dT = ctx.delta_time();

        flock.update(dT, target_dog, enclos);

        /* RENDERING LOOP */
        display_grass(ctx);
        display_border(ctx);
        ctx.fill = p6::NamedColor::White;
        ctx.text_size = 0.04f;
        auto topleftcorner = p6::TopLeftCorner(glm::vec2(-0.9f, 0.1f));
        ctx.text(u"BRAVO PLUS DE MOUTMOUT", topleftcorner);
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.9f, -0.1f));
        ctx.text(u"DANS L'ENCLOS EN :", topleftcorner);
        std::u16string time_score = to_u16string(int(timeofmylife / 10.f));
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.9f, -0.2f));
        ctx.text(time_score, topleftcorner);
        topleftcorner = p6::TopLeftCorner(glm::vec2(-0.9f, -0.3f));
        ctx.text(u"SECONDES", topleftcorner);
      };
    }

    ImGui::End();
  };

  ctx.background({0.1f, 0.75f, 0.1f, 0});

  display_grass(ctx);
  display_border(ctx);
  ctx.fill = p6::NamedColor::White;
  ctx.text_size = 0.04f;
  auto topleftcorner = p6::TopLeftCorner(glm::vec2(-0.7f, 0.1f));
  ctx.text(u"Choisi tes options", topleftcorner);
  topleftcorner = p6::TopLeftCorner(glm::vec2(-0.1f, -0.0f));
  ctx.text(u"et", topleftcorner);
  topleftcorner = p6::TopLeftCorner(glm::vec2(-0.7f, -0.1f));
  ctx.text(u"Demarre la partie !", topleftcorner);

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

  for (int i = 0; i < 1; i++) {
    std::cout << "Loi Beta pour la" << i << "eme fois :" << loiBeta(5.f, 1.f)
              << std::endl;
  }
};
