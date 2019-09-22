#include "EnemySoldier.h"
using namespace tank_battle;

EnemySoldier::EnemySoldier() 
	: Enemy("resources/sprites/soldier.png", 1)
{
}

sf::Vector2f EnemySoldier::getPositionToFire() const
{
	sf::Vector2f pos = sprite.getPosition();

	return sf::Vector2f(pos.x + 9.f, pos.y + 20.f);
}
