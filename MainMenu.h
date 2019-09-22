#pragma once
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameView.h"

namespace tank_battle
{
	enum GameButton
	{
		GAME_BUTTON_SINGLE_PLAYER,
		GAME_BUTTON_DUO_PLAYER
	};


	class MainMenu : public GameView
	{
	private:
		Button buttonSinglePlayer;
		Button buttonDuoPlayer;
		Button buttonExit;

		GameButton clickedButton;

		void gameLoop(sf::RenderWindow &) override;
		bool eventLoop(sf::RenderWindow &) override;
		void drawEntities(sf::RenderWindow &) override;
	public:
		MainMenu();

		GameButton getClickedButton() const;
		void show(sf::RenderWindow &) override;
	};
}
