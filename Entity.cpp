#include "Entity.h"
using namespace tank_battle;

Entity::~Entity() = default;

Entity::Entity(const std::string & filename)
{
	setTexture(filename);
}

void Entity::setTexture(const std::string & filename)
{
	try
	{
		if (!texture.loadFromFile(filename))
			throw load_error("Can not load the texture");
	}
	catch (const std::exception & ex)
	{
		MessageBox(NULL, ex.what(), "Error", MB_OK);
		exit(0);
	}

	sprite.setTexture(texture);

	texture.setSmooth(true);
}

sf::Rect <float> Entity::getGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.texture = sprite.getTexture();
	states.transform = sprite.getTransform();

	target.draw(sprite, states);
}

sf::Vector2f Entity::getPosition()
{
	return sprite.getPosition();
}

bool Entity::isCollision(std::shared_ptr<Entity> a) const
{
	sf::FloatRect spriteShape = sprite.getGlobalBounds();

	float aX = a->getPosition().x;
	float aY = a->getPosition().y;

	float spriteX = sprite.getPosition().x;
	float spriteY = sprite.getPosition().y;

	bool inRangeWidth = aX >= spriteX && aX <= (spriteX + spriteShape.width);
	bool inRangeHeight = aY >= spriteY && aY <= (spriteY + spriteShape.width);

	return inRangeWidth && inRangeHeight;
}

void tank_battle::Entity::setPosition(const sf::Vector2f & pos)
{
	sprite.setPosition(pos);
}

void tank_battle::Entity::rotate(float a)
{
	sprite.rotate(a);
}
