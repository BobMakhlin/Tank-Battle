#include "Enemy.h"
using namespace tank_battle;

Enemy::Enemy(int lives) : GameSprite(lives)
{
}

Enemy::Enemy(std::string filename, int lives) 
	: GameSprite(filename, lives)
{
}

void Enemy::_move()
{
	sprite.move(0, 35.5f);
}

