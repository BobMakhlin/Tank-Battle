#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Bullet.h"
#include "Enemies.h"
#include "GameOver.h"
#include "Statistics.h"
#include <algorithm>
#include <iterator>

namespace tank_battle
{
	class Bullets : public sf::Drawable
	{
	protected:
		void draw(sf::RenderTarget &, sf::RenderStates) const override;
	private:
		std::vector <std::shared_ptr<Bullet>> v;

		void delOutBullets();
	public:
		Bullets() = default;

		void pushBack(std::shared_ptr<Bullet>);

		void move(); 
		void detectCollisions(Enemies &, UsersTank &);
		void detectCollisions(UsersTank &, UsersTank &);

		void destroyAll();

		int getSize() { return v.size(); }
	};
}
