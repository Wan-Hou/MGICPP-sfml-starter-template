
#ifndef WHACKY_GAME_H
#define WHACKY_GAME_H

#include "Functions.h"
#include "GameObject.h"

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
  bool collisionCheck(sf::Vector2f click, GameObject gameobject);
  bool birdCollisionCheck(sf::Vector2f click, Bird bird);
  void spawn();
  void screen(AllScreenStates swap);

 private:
  sf::RenderWindow& window;
  GameObject background;
  Bird bird;
  sf::Font font_open_sans;

  AllScreenStates screen_state = AllScreenStates::In_Menu;
  AllScreenStates menu_selection = AllScreenStates::In_Menu;
  AllGameModes game_mode = AllGameModes::Bird;

  sf::Text score_text;
  sf::Text menu_text;
  sf::Text title_text;
  sf::Text play_option;
  sf::Text settings_option;
  sf::Text quit_option;

  bool reverse = false;

  unsigned int score = 0;

};

#endif // WHACKY_GAME_H
