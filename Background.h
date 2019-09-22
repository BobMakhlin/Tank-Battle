#pragma once
#include "Entity.h"

namespace tank_battle
{
	class Background : public Entity
	{
	public:
		~Background() override = default;
		Background() = default;

		Background(std::string);
	};
}
