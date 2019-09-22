#pragma once
#include "SinglePlayer.h"
#include "DuoPlayer.h"
#include "GameMode.h"
#include <memory>

namespace tank_battle
{
	class Game
	{
	private:
		sf::RenderWindow window;

		RecordsFile recordsFile;
	public:
		Game(); // Start.
	};
}
