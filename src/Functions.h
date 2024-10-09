#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <random>
#include <SFML/Graphics.hpp>

enum class AllScreenStates
{
	In_Menu,
	In_Settings,
	In_Game,
	In_End
};

void initText(sf::Text& text, const std::string& string, sf::Font& font,
	int size, sf::Color& color);

int RNGI(int a, int b);

float RNGF(float a, float b);

#endif // FUNCTIONS_H
