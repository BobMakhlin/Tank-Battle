#pragma once
#include "Entity.h"

namespace tank_battle
{
	class Bullet : public Entity
	{
	public:
		friend class Bullets;

		enum Direction
		{
			DIRECTION_UP,
			DIRECTION_DOWN
		};

		Bullet() = default;

		Bullet(std::string, sf::Vector2f, Bullet::Direction);
		Bullet(std::string, float, float, Bullet::Direction);

		~Bullet() override = default;

		void move();

		bool isOut();
	private:
		Direction direction;
	};
}