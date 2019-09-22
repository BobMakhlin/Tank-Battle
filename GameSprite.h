#pragma once
#include "Entity.h"

namespace tank_battle
{
	class GameSprite : public Entity
	{
	protected:
		int lives;
	public:
		GameSprite(int);
		GameSprite(std::string, int);

		void decreaseLives();
		void setLives(int);
		int getLives() const;
	};
}
