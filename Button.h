#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Windows.h>
#include "load_error.h"

namespace tank_battle
{
	class Button : public sf::RectangleShape
	{
	private:
		sf::Texture texture;
	public:
		Button(std::string, sf::Vector2f = sf::Vector2f(0, 0));

		bool isClicked(sf::Vector2i) const;
		bool isClicked(int, int) const;
	};
}

