#pragma once
#include "GameSprite.h"
#include <string>

namespace tank_battle
{
	class Enemy : public GameSprite
	{
	public:
		friend class Enemies;

		Enemy(int);
		Enemy(std::string, int);

		~Enemy() override = default;

		void _move();

		virtual sf::Vector2f getPositionToFire() const = 0;
	};
}
