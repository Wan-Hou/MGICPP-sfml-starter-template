#ifndef FUNCTIONS_GAME_H
#define FUNCTIONS_GAME_H

#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

void initText(sf::Text& text, const std::string& string, sf::Font& font,
	int size, sf::Color& color);

int RNGI(int a, int b);

float RNGF(float a, float b);

#endif // FUNCTIONS_GAME_H
