#pragma once
#include "Background.h"

namespace tank_battle
{
	class GameView
	{
	protected:
		Background background;

		virtual void gameLoop(sf::RenderWindow &) = 0;
		virtual bool eventLoop(sf::RenderWindow &) = 0; // Return true, if exit.
		virtual void drawEntities(sf::RenderWindow &) = 0;
	public:
		GameView(std::string);
		virtual ~GameView() = default;

		virtual void show(sf::RenderWindow &) = 0;
	};
}
