
#include "Functions.h"

//SFML Text Initializer
void initText(sf::Text& text, const std::string& string, sf::Font& font,
	int size, sf::Color& color)
{
	text.setString(string);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
}

//Random Number Generator Integer
int RNGI(int a = 0, int b = 0)
{
	std::random_device r;
	std::mt19937 mt(r());
	std::uniform_int_distribution<int> dist(a, b);
	return dist(mt);
}

//Random Number Generator Float
float RNGF(float a = 0, float b = 0)
{
	std::random_device r;
	std::mt19937 mt(r());
	std::uniform_real_distribution<float> dist(a, b);
	return dist(mt);
}