#include "Plane.h"
using namespace tank_battle;

Plane::Plane()
	: Entity("resources/sprites/plane.png")
{
}

void Plane::dislocate()
{
	switch (rand() % 4)
	{
	case 0:
		sprite.setPosition(sf::Vector2f(18.f, 180.f));
		break;
	case 1:
		sprite.setPosition(sf::Vector2f(54.f, 180.f));
		break;
	case 2:
		sprite.setPosition(sf::Vector2f(90.f, 180.f));
		break;
	case 3:
		sprite.setPosition(sf::Vector2f(126.f, 180.f));
		break;
	}
}

void Plane::_move()
{
	sprite.move(0, -20.f);

	if (sprite.getPosition().y <= 0)
		exist = false;
}

std::vector <sf::Vector2f> Plane::getPositionsToFire() const
{
	std::vector <sf::Vector2f> positions;
	positions.reserve(3);

	positions.push_back(sf::Vector2f(sprite.getPosition().x - 2.f, sprite.getPosition().y));
	positions.push_back(sf::Vector2f(sprite.getPosition().x + 33.f, sprite.getPosition().y));
	positions.push_back(sf::Vector2f(sprite.getPosition().x + 67.f, sprite.getPosition().y));

	return positions;
}

bool Plane::isExist() const
{
	return exist;
}

void Plane::setExist(bool exist)
{
	this->exist = exist;
}
