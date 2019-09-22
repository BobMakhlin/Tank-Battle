#pragma once
#include <vector>
#include "Entity.h"

namespace tank_battle
{
	class Plane : public Entity
	{
	private:
		bool exist;
	public:
		Plane();
		~Plane() override = default;

		void dislocate();

		void _move();

		std::vector <sf::Vector2f> getPositionsToFire() const;

		bool isExist() const;
		void setExist(bool);
	};
}
