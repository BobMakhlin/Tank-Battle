#pragma once
#include "GameSprite.h"

namespace tank_battle
{
	class UsersTank : public GameSprite
	{
	public:
		UsersTank();
		~UsersTank() override = default;

		void dislocate();

		void moveLeft();
		void moveRight();
	};
}
