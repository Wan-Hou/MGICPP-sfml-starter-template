
#include "Game.h"

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	initObject();
	initDisplay();

  return true;
}

void Game::initObject()
{
	if(!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);

	if (!bird_texture.loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird texture did not load \n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(100, 100);
	bird.setScale(0.5,0.5);
}

void Game::initFont()
{
	if (!font_open_sans.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load \n";
	}
}

void Game::initDisplay()
{
	initFont();

	auto& colour = const_cast<sf::Color&>(sf::Color(255, 255, 255, 128));
	initText(title_text, "Whack-A-Bird", font_open_sans, 150, colour);
	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2
	);
}

void Game::update(float dt)
{

}

void Game::render()
{
	window.draw(background);
	window.draw(bird);
	window.draw(title_text);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window) - sf::Vector2i(15, 2);


}

void Game::keyPressed(sf::Event event)
{

}


