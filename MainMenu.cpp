#include "MainMenu.h"
using namespace tank_battle;

MainMenu::MainMenu()
	: 
	GameView("resources/main_menu/main_menu.jpg"),
	buttonSinglePlayer("resources/main_menu/single_player_button.png", sf::Vector2f(300, 89)),
	buttonDuoPlayer("resources/main_menu/duo_player_button.png", sf::Vector2f(300, 89)),
	buttonExit("resources/main_menu/exit_button.png", sf::Vector2f(300, 89))
{
	buttonSinglePlayer.setPosition(sf::Vector2f(60.f, 140.f));
	buttonDuoPlayer.setPosition(sf::Vector2f(60.f, 250.f));
	buttonExit.setPosition(sf::Vector2f(60.f, 360.f));
}

void MainMenu::gameLoop(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		if (eventLoop(window))
			return;

		drawEntities(window);
	}
}

bool MainMenu::eventLoop(sf::RenderWindow & window)
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (_event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttonSinglePlayer.isClicked(sf::Mouse::getPosition(window)))
				{
					clickedButton = GameButton::GAME_BUTTON_SINGLE_PLAYER;
					return true; // Exit.
				}
				else if (buttonDuoPlayer.isClicked(sf::Mouse::getPosition(window)))
				{
					clickedButton = GameButton::GAME_BUTTON_DUO_PLAYER;
					return true; // Exit.
				}
				else if (buttonExit.isClicked(sf::Mouse::getPosition(window)))
					window.close();
			}
			break;

		case sf::Event::Closed:
			window.close();
		}
	}

	return false;
}

void MainMenu::drawEntities(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(buttonSinglePlayer);
	window.draw(buttonDuoPlayer);
	window.draw(buttonExit);

	window.display();
}

void MainMenu::show(sf::RenderWindow & window)
{
	gameLoop(window);
}

GameButton MainMenu::getClickedButton() const
{
	return clickedButton;
}
