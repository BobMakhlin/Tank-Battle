#include "UsersTank.h"
using namespace tank_battle;

UsersTank::UsersTank() 
	: GameSprite("resources/sprites/tank.png", 3)
{
	dislocate();
}

void UsersTank::moveLeft()
{
	if(sprite.getPosition().x > 8.5)
		sprite.move(-35.5f, 0.f);
}

void UsersTank::moveRight()
{
	if (sprite.getPosition().x < 186)
		sprite.move(35.5f, 0.f);
}

void UsersTank::dislocate()
{
	sprite.setPosition(79.5f, 210.f);
}
