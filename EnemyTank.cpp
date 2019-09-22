#include "EnemyTank.h"
using namespace tank_battle;

EnemyTank::EnemyTank() : Enemy(2)
{
	switch (rand() % 2)
	{
	case 0:
		setTexture("resources/sprites/enemy_tank_a.png");
		break;
	case 1:
		setTexture("resources/sprites/enemy_tank_b.png");
		break;
	}
}

tank_battle::EnemyTank::EnemyTank(const std::string & _texture)
	: Enemy(_texture, 3)
{
}

sf::Vector2f EnemyTank::getPositionToFire() const
{
	sf::Vector2f pos = sprite.getPosition();

	return sf::Vector2f(pos.x + 7.3f, pos.y + 45.f);
}
