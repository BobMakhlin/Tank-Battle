#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "GameView.h"
#include "RecordsFile.h"

namespace tank_battle
{
	class SplashScreen : public GameView
	{
	private:
		sf::Font font;
		sf::Text text;
		sf::Text maxScore;
		sf::Text timeRecord;

		void gameLoop(sf::RenderWindow &) override;
		bool eventLoop(sf::RenderWindow &) override;
		void drawEntities(sf::RenderWindow &) override;

		void changeTextColor(const sf::Time &);
	public:
		SplashScreen(const RecordsFile &);
		~SplashScreen() override = default;

		void show(sf::RenderWindow &) override;
	};
}
