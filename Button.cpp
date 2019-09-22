#include "Button.h"
using namespace tank_battle;

Button::Button(std::string filename, sf::Vector2f size) : RectangleShape(size)
{
	try
	{
		if (!texture.loadFromFile(filename))
			throw load_error("Can not load the texture");
	}
	catch (const std::exception & ex)
	{
		MessageBox(NULL, ex.what(), "Error", MB_OK);
		exit(0);
	}

	setTexture(&texture);

	texture.setSmooth(true);
}

bool Button::isClicked(sf::Vector2i mouse) const
{
	auto tmp = getGlobalBounds();
	return tmp.contains(sf::Vector2f(mouse));
}

bool Button::isClicked(int x, int y) const
{
	return isClicked(sf::Vector2i(x, y));
}