#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "RecordsFile.h"
#include "Statistics.h"
#include "UsersTank.h"
#include "Bullets.h"

namespace tank_battle 
{
	class GameMode
	{
	protected:
		// BG.
		Background background;

		// UsersTank.
		UsersTank usersTank;

		// Game time.
		sf::Clock gameTime;

		// Bullets.
		Bullets bullets;

		virtual void gameLoop(sf::RenderWindow &) = 0;
		virtual void eventLoop(sf::RenderWindow &) = 0;
		virtual void drawEntities(sf::RenderWindow &) = 0;

		virtual bool checkLives() = 0;

		void loadBg();
		void updateTitle(sf::RenderWindow &);
	public:
		GameMode() = default;
		virtual ~GameMode() = default;
	};
}
