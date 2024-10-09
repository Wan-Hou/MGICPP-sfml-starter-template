
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

	colour = const_cast<sf::Color&>(sf::Color(247, 40, 46, 255));
	initText(menu_text, "WHACK", font_open_sans, 200, colour);
	menu_text.setPosition
	(
		window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
		menu_text.getGlobalBounds().height / 3
	);

	initText(play_option, "Play", font_open_sans, 75, colour);
	play_option.setPosition
	(
		window.getSize().x / 6,
		menu_text.getPosition().y +
		menu_text.getGlobalBounds().height
		+ play_option.getGlobalBounds().height * 2
	);

	initText(settings_option, "Settings", font_open_sans, 75, colour);
	settings_option.setPosition
	(
		window.getSize().x / 2
		- settings_option.getGlobalBounds().width / 2,
		menu_text.getPosition().y +
		menu_text.getGlobalBounds().height
		+ play_option.getGlobalBounds().height * 4
	);

	initText(quit_option, "Quit", font_open_sans, 75, colour);
	quit_option.setPosition
	(
		window.getSize().x * 5 / 6
		- quit_option.getGlobalBounds().width,
		menu_text.getPosition().y +
		menu_text.getGlobalBounds().height
		+ play_option.getGlobalBounds().height * 2
	);

	initText(score_text, std::to_string(score), font_open_sans, 50, colour);
	score_text.setPosition
	(
		window.getSize().x - score_text.getGlobalBounds().width * 2,
		score_text.getGlobalBounds().height / 2
	);
}

void Game::update(float dt)
{
	mouseHover();

	switch (screen_state)
	{
		case AllScreenStates::In_Game:
		{
			birdMovement(dt);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Game::render()
{
	switch (screen_state)
	{
		case AllScreenStates::In_Menu:
		{
			window.clear(sf::Color(243, 233, 105, 255));
			window.draw(menu_text);
			window.draw(play_option);
			window.draw(settings_option);
			window.draw(quit_option);
			break;
		}
		case AllScreenStates::In_Settings:
		{
			break;
		}
		case AllScreenStates::In_Game:
		{
			window.draw(background);
			window.draw(score_text);
			window.draw(title_text);
			window.draw(bird);
			break;
		}
		case AllScreenStates::In_End:
		{
			window.draw(background);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Game::mouseHover()
{
	sf::Vector2f hover = static_cast<sf::Vector2f>
		(sf::Mouse::getPosition(window)) - sf::Vector2f(15, 2);

	switch (screen_state)
	{
		case AllScreenStates::In_Menu:
		{
			sf::Color default_menu_colour = sf::Color(247, 40, 46, 255);
			sf::Color hover_menu_colour = sf::Color(247, 150, 155, 255);

			bool play_x_check = play_option.getPosition().x <= hover.x &&
				play_option.getPosition().x +
				play_option.getGlobalBounds().width >= hover.x;

			bool play_y_check = play_option.getPosition().y <= hover.y &&
				play_option.getPosition().y +
				play_option.getGlobalBounds().height >= hover.y;

			bool settings_x_check = settings_option.getPosition().x <= hover.x &&
				settings_option.getPosition().x +
				settings_option.getGlobalBounds().width >= hover.x;

			bool settings_y_check = settings_option.getPosition().y <= hover.y &&
				settings_option.getPosition().y +
				settings_option.getGlobalBounds().height >= hover.y;

			bool exit_x_check = quit_option.getPosition().x <= hover.x &&
				quit_option.getPosition().x +
				quit_option.getGlobalBounds().width >= hover.x;

			bool exit_y_check = quit_option.getPosition().y <= hover.y &&
				quit_option.getPosition().y +
				quit_option.getGlobalBounds().height >= hover.y;

			if (play_x_check && play_y_check)
			{
				menu_selection = AllScreenStates::In_Menu;
				play_option.setFillColor(hover_menu_colour);
				settings_option.setFillColor(default_menu_colour);
				quit_option.setFillColor(default_menu_colour);
			}
			else if (settings_x_check && settings_y_check)
			{
				menu_selection = AllScreenStates::In_Menu;
				play_option.setFillColor(default_menu_colour);
				settings_option.setFillColor(hover_menu_colour);
				quit_option.setFillColor(default_menu_colour);
			}
			else if (exit_x_check && exit_y_check)
			{
				menu_selection = AllScreenStates::In_Menu;
				play_option.setFillColor(default_menu_colour);
				settings_option.setFillColor(default_menu_colour);
				quit_option.setFillColor(hover_menu_colour);
			}
			else if (menu_selection == AllScreenStates::In_Menu)
			{
				play_option.setFillColor(default_menu_colour);
				settings_option.setFillColor(default_menu_colour);
				quit_option.setFillColor(default_menu_colour);
			}

			break;
		}
		case AllScreenStates::In_End:
		default:
		{
			break;
		}
	}
}

void Game::mouseClicked(sf::Event event)
{
	//get the click position
	sf::Vector2f click = static_cast<sf::Vector2f>
		(sf::Mouse::getPosition(window)) - sf::Vector2f(15, 2);

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		switch (screen_state)
		{
			case AllScreenStates::In_Menu:
			{
				sf::Color default_menu_colour = sf::Color(247, 40, 46, 255);
				sf::Color hover_menu_colour = sf::Color(247, 150, 155, 255);

				if (play_option.getFillColor() == hover_menu_colour)
				{
					play_option.setFillColor(default_menu_colour);
					screen(AllScreenStates::In_Game);
				}

				else if (settings_option.getFillColor() == hover_menu_colour)
				{
					settings_option.setFillColor(default_menu_colour);
					screen(AllScreenStates::In_Settings);
				}

				else if (quit_option.getFillColor() == hover_menu_colour)
				{
					window.close();
				}

				break;
			}
			case AllScreenStates::In_Game:
			{
				if (collisionCheck(click, bird))
				{
					spawn();
				}

				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void Game::keyPressed(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Left)
	{
		switch (screen_state)
		{
			case AllScreenStates::In_Menu:
			{
				sf::Color default_menu_colour = sf::Color(247, 40, 46, 255);
				sf::Color hover_menu_colour = sf::Color(247, 150, 155, 255);

				switch (menu_selection)
				{
					case AllScreenStates::In_Menu:
					{
						menu_selection = AllScreenStates::In_End;
						quit_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_Settings:
					{
						menu_selection = AllScreenStates::In_Game;
						settings_option.setFillColor(default_menu_colour);
						play_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_Game:
					{
						menu_selection = AllScreenStates::In_End;
						play_option.setFillColor(default_menu_colour);
						quit_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_End:
					{
						menu_selection = AllScreenStates::In_Settings;
						quit_option.setFillColor(default_menu_colour);
						settings_option.setFillColor(hover_menu_colour);

						break;
					}
					default:
					{
						break;
					}
				}

				break;
			}
			default:
			{
				break;
			}
		}
	}

	if (event.key.code == sf::Keyboard::Right)
	{
		switch (screen_state)
		{
			case AllScreenStates::In_Menu:
			{
				sf::Color default_menu_colour = sf::Color(247, 40, 46, 255);
				sf::Color hover_menu_colour = sf::Color(247, 150, 155, 255);

				switch (menu_selection)
				{
					case AllScreenStates::In_Menu:
					{
						menu_selection = AllScreenStates::In_Game;
						play_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_Settings:
					{
						menu_selection = AllScreenStates::In_End;
						settings_option.setFillColor(default_menu_colour);
						quit_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_Game:
					{
						menu_selection = AllScreenStates::In_Settings;
						play_option.setFillColor(default_menu_colour);
						settings_option.setFillColor(hover_menu_colour);

						break;
					}
					case AllScreenStates::In_End:
					{
						menu_selection = AllScreenStates::In_Game;
						quit_option.setFillColor(default_menu_colour);
						play_option.setFillColor(hover_menu_colour);

						break;
					}
					default:
					{
						break;
					}
				}

				break;
			}
			default:
			{
				break;
			}
		}
	}

	if (event.key.code == sf::Keyboard::Enter ||
		event.key.code == sf::Keyboard::Space)
	{
		switch (screen_state)
		{
			case AllScreenStates::In_Menu:
			{
				sf::Color default_menu_colour = sf::Color(247, 40, 46, 255);
				sf::Color hover_menu_colour = sf::Color(247, 150, 155, 255);

				if (play_option.getFillColor() == hover_menu_colour)
				{
					play_option.setFillColor(default_menu_colour);
					screen(AllScreenStates::In_Game);
				}

				else if (settings_option.getFillColor() == hover_menu_colour)
				{
					settings_option.setFillColor(default_menu_colour);
					screen(AllScreenStates::In_Settings);
				}

				else if (quit_option.getFillColor() == hover_menu_colour)
				{
					window.close();
				}

				menu_selection = AllScreenStates::In_Menu;

				break;
			}
			default:
			{
				break;
			}
		}
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		if (screen_state != AllScreenStates::In_Menu)
		{
			screen(AllScreenStates::In_Menu);
		}
		else
		{
			window.close();
		}
	}

}

bool Game::collisionCheck(sf::Vector2f click, sf::Sprite sprite)
{
	if (click.x >= sprite.getPosition().x &&
		click.x <= sprite.getPosition().x + sprite.getGlobalBounds().width)
	{
		if (click.y >= sprite.getPosition().y &&
			click.y <= sprite.getPosition().y + sprite.getGlobalBounds().height)
		{
			score++;
			score_text.setString(std::to_string(score));
			float confirm = std::log10(score) - static_cast<int>(std::log10(score));
			if (confirm == 0)
			{
				score_text.setPosition
				(
					window.getSize().x - 50 - std::log10(score) * 25,
					score_text.getGlobalBounds().height / 2
				);
			}
			return true;
		}
	}
	return false;

}

void Game::birdMovement(float dt)
{
	if (reverse)
	{
		bird.move(1.0f * speed * dt, 0);
		bird.setTextureRect
		(
			sf::IntRect
			(
				0, 0,
				bird.getLocalBounds().width,
				bird.getLocalBounds().height
			)
		);
	}
	else
	{
		bird.move(-1.0f * speed * dt, 0);
		bird.setTextureRect
		(
			sf::IntRect
			(
				bird.getLocalBounds().width, 0,
				-bird.getLocalBounds().width,
				bird.getLocalBounds().height
			)
		);
	}

	if ((bird.getPosition().x >
		(window.getSize().x - bird.getGlobalBounds().width)) ||
		(bird.getPosition().x < 0))
	{
		reverse = !reverse;
	}
}

void Game::spawn()
{
	bird.setPosition
	(
		RNGF(0, static_cast<float>(window.getSize().x) - bird.getGlobalBounds().width),
		RNGF(0, static_cast<float>(window.getSize().y) - bird.getGlobalBounds().height)
	);
	reverse = RNGI(0, 1);
	speed = RNGF(100, 1000);
	
}

void Game::screen(AllScreenStates swap)
{

	switch (swap)
	{
		case AllScreenStates::In_Game:
		default:
		{
			if (screen_state != swap)
			{
				screen_state = swap;
			}
			break;
		}
	}
}
