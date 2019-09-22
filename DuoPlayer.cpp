#include "DuoPlayer.h"
#include <iostream>
using namespace tank_battle;

duo_player::DuoPlayer::DuoPlayer(sf::RenderWindow & window)
{
	// BG.
	loadBg();

	player1.setTexture("resources/sprites/tank_a.png");
	player1.setPosition(sf::Vector2f(8.5f, 2.1f));

	// Game loop.
	gameLoop(window);
}

void duo_player::DuoPlayer::gameLoop(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		eventLoop(window);
		drawEntities(window);

		// Bullets.
		bullets.move();

		bullets.detectCollisions(player1, usersTank);

		if (checkLives())
		{
			GameOver gameOver;

			std::string tmp = "The winner is the ";

			if (player1.getLives() > usersTank.getLives())
				tmp += "\n\t\tplayer1";
			else if (usersTank.getLives() > player1.getLives())
				tmp += "\n\t\tplayer2";
			else
				tmp = "It's a draw!";

			gameOver.setText(tmp);
			gameOver.show(window);

			restart();
		}
	}
}

void duo_player::DuoPlayer::eventLoop(sf::RenderWindow & window)
{
	sf::Vector2f tmp;

	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::Closed:
			window.close();

		case sf::Event::KeyPressed:
			switch (_event.key.code)
			{
			case sf::Keyboard::Left:
				usersTank.moveLeft();
				break;
			case sf::Keyboard::Right:
				usersTank.moveRight();
				break;
			case sf::Keyboard::A:
				player1.moveLeft();
				break;
			case sf::Keyboard::D:
				player1.moveRight();
				break;
			}
			break;
		case sf::Event::KeyReleased:
			switch (_event.key.code)
			{
			case sf::Keyboard::Up:
				tmp = usersTank.getPosition();
				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", tmp.x + 7.3f, tmp.y - 3.f, Bullet::DIRECTION_UP)));
				break;
			case sf::Keyboard::W:
				tmp = player1.getPosition();
				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", tmp.x + 7.3f, tmp.y + 40.f, Bullet::DIRECTION_DOWN)));
				break;
			}
			break;
		}
	}
}

void duo_player::DuoPlayer::drawEntities(sf::RenderWindow & window)
{
	window.clear();

	window.draw(background);
	window.draw(usersTank);
	window.draw(player1);
	window.draw(bullets);

	window.display();
}

bool duo_player::DuoPlayer::checkLives()
{
	return usersTank.getLives() <= 0 || player1.getLives() <= 0;
}

void duo_player::DuoPlayer::restart()
{
	usersTank.setLives(3);
	player1.setLives(3);

	bullets.destroyAll();

	loadBg();
}
