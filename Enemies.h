#pragma once
#include "EnemyTank.h"
#include "EnemySoldier.h"
#include "UsersTank.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Statistics.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>

namespace tank_battle
{
	class Enemies : public sf::Drawable
	{
	protected:
		void draw(sf::RenderTarget &, sf::RenderStates) const override;
	private:
		std::vector <std::shared_ptr<Enemy>> v;

		static const int MAX_ENEMIES_COUNT;

		static int spawnPosition;

		bool isInFirstLine(std::shared_ptr<Enemy>) const;

		friend class Bullets;
	public:
		Enemies();

		void pushBack(std::shared_ptr<Enemy>);
		void move(UsersTank, Statistics &);
		bool isEmptyPosition(sf::Vector2f) const;

		std::vector<std::shared_ptr<Enemy>> getFirstLine() const;

		void destroyAll();

		void checkLives(Statistics &);
	};
}
