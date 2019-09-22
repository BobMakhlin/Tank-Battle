#pragma once
#include "GameView.h"
#include "Button.h"
#include "Statistics.h"
#include "RecordsFile.h"

namespace tank_battle
{
	namespace single_player
	{
		class GameOver : public GameView
		{
		private:
			Button buttonPlay;
			Button buttonExit;

			sf::Font font;
			sf::Text score;
			sf::Text bestTime;
			sf::Text soldiersDestroyed;
			sf::Text tanksDestroyed;

			void gameLoop(sf::RenderWindow &) override;
			bool eventLoop(sf::RenderWindow &) override;
			void drawEntities(sf::RenderWindow &) override;

		public:
			GameOver(const Statistics &, const RecordsFile &);

			void show(sf::RenderWindow &) override;
		};
	}
	namespace duo_player
	{
		class GameOver : public GameView
		{
		private:
			Button buttonPlay;
			Button buttonExit;

			sf::Font font;
			sf::Text info;

			void gameLoop(sf::RenderWindow &) override;
			bool eventLoop(sf::RenderWindow &) override;
			void drawEntities(sf::RenderWindow &) override;
		public:
			GameOver();

			void show(sf::RenderWindow &) override;

			void setText(const std::string &);
		};
	}
}
