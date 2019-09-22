#include "GameSprite.h"
using namespace tank_battle;

GameSprite::GameSprite(int lives) : lives(lives)
{
}

GameSprite::GameSprite(std::string filename, int lives) 
	: Entity(filename)
{
	this->lives = lives;
}

void GameSprite::decreaseLives()
{
	lives--;
}

void GameSprite::setLives(int _lives)
{
	lives = _lives;
}

int GameSprite::getLives() const
{
	return lives;
}
