#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "SplashScreen.h"
#include "GameOver.h"
#include "MainMenu.h"
#include "Background.h"
#include "UsersTank.h"
#include "Enemies.h"
#include "Bullets.h"
#include "Statistics.h"
#include "RecordsFile.h"
#include "Plane.h"
#include "GameMode.h"

namespace tank_battle
{
	namespace single_player
	{
		class SinglePlayer : public GameMode
		{
		private:
			// Sprites.
			Enemies enemies;
			Plane plane;

			// Statistics.
			RecordsFile recordsFile;
			Statistics statistics;

			// Score
			sf::Font font;
			sf::Text scoreText;

			void gameLoop(sf::RenderWindow &) override;
			void eventLoop(sf::RenderWindow &) override;
			void drawEntities(sf::RenderWindow &) override;

			bool checkLives() override;

			void restart();
			void restartTime(sf::Clock &, sf::Clock &, sf::Clock &, sf::Clock &, sf::Clock &, sf::Clock &);

			void updateScoreText();
			void update(sf::RenderWindow &);
		public:
			SinglePlayer(sf::RenderWindow &, const RecordsFile &); // Start.
		};
	}
}
