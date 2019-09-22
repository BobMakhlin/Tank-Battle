#pragma once

namespace tank_battle
{
	struct Statistics
	{
		int score = 0;
		int tanksDestroyed = 0;
		int soldiersDestroyed = 0;

		Statistics() = default;

		void reset()
		{
			score = 0;
			tanksDestroyed = 0;
			soldiersDestroyed = 0;
		}
	};
}
