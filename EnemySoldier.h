#pragma once
#include "Enemy.h"

namespace tank_battle
{
	class EnemySoldier : public Enemy
	{
	public:
		EnemySoldier();
		~EnemySoldier() override = default;

		sf::Vector2f getPositionToFire() const override;
	};
}

