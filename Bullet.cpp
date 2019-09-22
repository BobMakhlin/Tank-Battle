#include "Bullet.h"
using namespace tank_battle;

Bullet::Bullet(std::string filename, sf::Vector2f pos, Bullet::Direction dir)
	: Entity(filename)
{
	sprite.setPosition(pos);
	direction = dir;
}

Bullet::Bullet(std::string filename, float posX, float posY, Bullet::Direction dir)
	: Bullet(filename, sf::Vector2f(posX, posY), dir)
{
}

void Bullet::move()
{
	if (direction == Bullet::Direction::DIRECTION_UP)
		sprite.move(0, -1);
	else
		sprite.move(0, 1);
}

bool tank_battle::Bullet::isOut() 
{
	return direction == DIRECTION_UP ? 
		getPosition().y <= 0 : getPosition().y >= 248.5;
}

