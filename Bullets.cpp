#include "Bullets.h"
using namespace tank_battle;

void Bullets::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < v.size(); i++)
	{
		states.texture = v[i]->sprite.getTexture();
		states.transform = v[i]->sprite.getTransform();

		target.draw(*v[i], states);
	}
}

void tank_battle::Bullets::delOutBullets()
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->isOut())
		{
			v.erase(v.begin() + i);
		}
	}
}

void Bullets::move()
{
	transform(v.begin(), v.end(), v.begin(), [](std::shared_ptr<Bullet> elem)
	{
		elem->move();
		return elem;
	});
}

void Bullets::detectCollisions(Enemies & enemies, UsersTank & usersTank)
{
	bool bulletDestroyed;
	for (int i = 0; i < enemies.v.size(); i++)
	{
		bulletDestroyed = false;
		for (int j = 0; j < v.size() && !bulletDestroyed; j++)
		{
			if (v[j]->direction == Bullet::DIRECTION_UP)
			{
				if (enemies.v[i]->isCollision(v[j]))
				{
					enemies.v[i]->decreaseLives();
					v.erase(v.begin() + j);

					bulletDestroyed = true;
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->direction == Bullet::DIRECTION_DOWN)
		{
			if (usersTank.isCollision(v[i]))
			{
				usersTank.decreaseLives();
				v.erase(v.begin() + i);
				break;
			}
		}
	}

	delOutBullets();
}

void Bullets::detectCollisions(UsersTank & ut1, UsersTank & ut2)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->direction == Bullet::DIRECTION_UP)
		{
			if(ut1.isCollision(v[i]))
			{
				ut1.decreaseLives();
				v.erase(v.begin() + i);
				i--;
			}
		}
		else
		{
			if (ut2.isCollision(v[i]))
			{
				ut2.decreaseLives();
				v.erase(v.begin() + i);
				i--;
			}
		}
	}

	delOutBullets();
}

void Bullets::pushBack(std::shared_ptr<Bullet> bullet)
{
	v.push_back(bullet);
}

void Bullets::destroyAll()
{
	v.resize(0);
	v.shrink_to_fit();
}
