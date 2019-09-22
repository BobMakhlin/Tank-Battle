#include "Game.h"
using namespace tank_battle;

Game::Game() 
	: window(sf::VideoMode(420, 500), "Tank Battle", sf::Style::Close)
{
	// Splash screen.
	SplashScreen splashScreen(recordsFile);
	splashScreen.show(window);

	// Main menu.
	MainMenu mainMenu;
	mainMenu.show(window);

	auto tmp = mainMenu.getClickedButton();

	if (tmp == GAME_BUTTON_SINGLE_PLAYER)
		single_player::SinglePlayer singlePlayer(window, recordsFile);
	else
		duo_player::DuoPlayer duoPlayer(window);
}
