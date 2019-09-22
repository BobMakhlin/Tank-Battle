#pragma once
#include "GameMode.h"
#include "Enemies.h"
#include "GameOver.h"
#include <memory>

namespace tank_battle
{
	namespace duo_player
	{
		class DuoPlayer : public GameMode
		{
			UsersTank player1;

			void gameLoop(sf::RenderWindow &) override;
			void eventLoop(sf::RenderWindow &) override;
			void drawEntities(sf::RenderWindow &) override;

			bool checkLives() override;

			void restart();
		public:
			DuoPlayer(sf::RenderWindow &);
		};
	}
}
