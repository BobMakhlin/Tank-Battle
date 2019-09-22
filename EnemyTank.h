#pragma once
#include "Entity.h"
#include "Enemy.h"

namespace tank_battle
{
	class EnemyTank : public Enemy
	{
	public:
		EnemyTank();
		EnemyTank(const std::string &);
		~EnemyTank() override = default;
		
		sf::Vector2f getPositionToFire() const override;
	};
}
