
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Functions.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void initObject();
  void initFont();
  void initDisplay();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite bird;
  sf::Texture bird_texture;
  sf::Font font_open_sans;

  sf::Text score_text;
  sf::Text selector;
  sf::Text menu_text;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text settings_option;
  sf::Text quit_option;
  sf::Text settings_text;
  sf::Text settings_mode_1;
  sf::Text settings_mode_2;
  sf::Text settings_exit;

};

#endif // PLATFORMER_GAME_H
