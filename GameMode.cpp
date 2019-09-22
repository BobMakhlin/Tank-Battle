#include "GameMode.h"
using namespace tank_battle;

void tank_battle::GameMode::loadBg()
{
	switch (rand() % 3)
	{
	case 0:
		background.setTexture("resources/bg/bg_grass.jpg");
		break;
	case 1:
		background.setTexture("resources/bg/bg_desert.jpg");
		break;
	case 2:
		background.setTexture("resources/bg/bg_snow.jpg");
		break;
	}
}

void tank_battle::GameMode::updateTitle(sf::RenderWindow & window)
{
	window.setTitle("Tank Battle                          "
		+ std::to_string(gameTime.getElapsedTime().asSeconds()));
}
