#include "Enemies.h"
using namespace tank_battle;

const int Enemies::MAX_ENEMIES_COUNT = 7;
int Enemies::spawnPosition = 0;

Enemies::Enemies()
{
	v.reserve(MAX_ENEMIES_COUNT);
}

void Enemies::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < v.size(); i++)
	{
		states.texture = &v[i]->texture;
		states.transform = v[i]->sprite.getTransform();

		target.draw(*v[i], states);
	}
}

void Enemies::pushBack(std::shared_ptr<Enemy> enemy)
{
	if (v.size() > MAX_ENEMIES_COUNT)
		return;

	sf::Vector2f position(spawnPosition * 35.5f + 8.5f, 2.1f);

	if (isEmptyPosition(position))
	{
		v.push_back(enemy); 
		v[v.size() - 1]->sprite.setPosition(position);
	}

	spawnPosition++;

	if (spawnPosition == 6)
		spawnPosition = 0;
}

void Enemies::move(UsersTank usersTank, Statistics & statistics)
{
	for (int i = 0; i < v.size(); i++)
	{
		sf::Vector2f nextPosition = sf::Vector2f(v[i]->getPosition().x, v[i]->getPosition().y + 35.5f);
		
		if (rand() % 2) 
			if(isEmptyPosition(nextPosition) && usersTank.getPosition() != sf::Vector2f(v[i]->getPosition().x, v[i]->getPosition().y + 30.4f))
				v[i]->_move(); 

		if (v[i]->getPosition().y >= 248.5)
		{
			statistics.score -= 10;

			v.erase(v.begin() + i);
		}
	} 
}

bool Enemies::isEmptyPosition(sf::Vector2f position) const
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getPosition() == position)
			return false;
	}
	return true;
}

bool Enemies::isInFirstLine(std::shared_ptr<Enemy> enemy) const
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getPosition().x == enemy->getPosition().x && v[i]->getPosition().y > enemy->getPosition().y)
			return false;
	}
	return true;
}

std::vector <std::shared_ptr<Enemy>> Enemies::getFirstLine() const
{
	std::vector <std::shared_ptr<Enemy>> firstLine;

	for (int i = 0; i < v.size(); i++)
	{
		if (isInFirstLine(v[i]))
			firstLine.push_back(v[i]);
	}

	return firstLine;
}

void Enemies::destroyAll()
{
	v.resize(0);
	v.shrink_to_fit();
}

void Enemies::checkLives(Statistics & stat)
{
	std::shared_ptr<EnemyTank> et;
	std::shared_ptr<EnemySoldier> es;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getLives() <= 0)
		{
			et = std::dynamic_pointer_cast<EnemyTank>(v[i]);

			if (et)
			{
				stat.tanksDestroyed++;
				stat.score += 10;
			}

			es = std::dynamic_pointer_cast<EnemySoldier>(v[i]);

			if (es)
			{
				stat.soldiersDestroyed++;
				stat.score += 5;
			}

			v.erase(v.begin() + i);
		}
	}
}
