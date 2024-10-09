
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
  void mouseHover();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void birdMovement(float dt);
  bool collisionCheck(sf::Vector2f click, sf::Sprite sprite);
  void spawn();
  void screen(AllScreenStates swap);

 private:
  sf::RenderWindow& window;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite bird;
  sf::Texture bird_texture;
  sf::Font font_open_sans;

  AllScreenStates screen_state = AllScreenStates::In_Menu;
  AllScreenStates menu_selection = AllScreenStates::In_Menu;

  sf::Text score_text;
  sf::Text menu_text;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text settings_option;
  sf::Text quit_option;

  bool reverse = false;
  float speed = 200;

  int menu_integer = 0;
  unsigned int score = 0;

};

#endif // PLATFORMER_GAME_H
