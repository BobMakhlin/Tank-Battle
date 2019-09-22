#include "SinglePlayer.h"
using namespace tank_battle;

single_player::SinglePlayer::SinglePlayer(sf::RenderWindow & window, const RecordsFile & recFile)
{
	// BG.
	loadBg();

	recordsFile = recFile;

	// Score.
	try
	{
		if (!font.loadFromFile("resources/arial.ttf"))
			throw load_error("Can not load the font");
	}
	catch (const std::exception & ex)
	{
		MessageBox(NULL, ex.what(), "Error", MB_OK);
		exit(0);
	}
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color(0, 0, 0, 128));
	scoreText.setPosition(sf::Vector2f(5, 5));
	scoreText.setString(std::to_string(statistics.score));

	// Game loop.
	gameLoop(window);
}

void single_player::SinglePlayer::gameLoop(sf::RenderWindow & window)
{
	// Enemies' time.
	sf::Clock enemiesSpawnTime;
	sf::Clock enemiesMoveTime;
	sf::Clock enemiesFireTime;

	// Plane's time.
	sf::Clock planeSpawnTime;
	sf::Clock planeMoveTime;
	sf::Clock planeFireTime;

	gameTime.restart();

	while (window.isOpen())
	{
		eventLoop(window);

		drawEntities(window);

		// Enemies.

		if (enemiesSpawnTime.getElapsedTime().asSeconds() > 1.2f)
		{
			if (rand() % 2)
			{
				switch (rand() % 2)
				{
				case 0:
					enemies.pushBack(std::shared_ptr<EnemyTank>(new EnemyTank));
					break;
				case 1:
					enemies.pushBack(std::shared_ptr<EnemySoldier>(new EnemySoldier));
					break;
				}
			}

			enemiesSpawnTime.restart();
		}

		if (enemiesMoveTime.getElapsedTime().asSeconds() > 1.f) // Move every second.
		{
			enemies.move(usersTank, statistics);

			enemiesMoveTime.restart();
		}

		if (enemiesFireTime.getElapsedTime().asSeconds() > 1.f)
		{
			std::vector <std::shared_ptr<Enemy>> firstLine = enemies.getFirstLine();
			sf::Vector2f pos;

			for (int i = 0; i < firstLine.size(); i++)
			{
				pos = firstLine[i]->getPosition();
				if (rand() % 2)
					bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", firstLine[i]->getPositionToFire(), Bullet::Direction::DIRECTION_DOWN)));
			}

			enemiesFireTime.restart();
		}

		// Plane.

		if (planeSpawnTime.getElapsedTime().asSeconds() > 120.f)
		{
			plane.setExist(true);
			plane.dislocate();

			planeSpawnTime.restart();
		}

		if (plane.isExist())
		{
			if (planeMoveTime.getElapsedTime().asSeconds() > 1.f)
			{
				plane._move();

				planeMoveTime.restart();
			}

			if (planeFireTime.getElapsedTime().asSeconds() > 0.7f)
			{
				std::vector <sf::Vector2f> positions = plane.getPositionsToFire();

				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", positions[0], Bullet::Direction::DIRECTION_UP)));
				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", positions[1], Bullet::Direction::DIRECTION_UP)));
				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", positions[2], Bullet::Direction::DIRECTION_UP)));

				planeFireTime.restart();
			}
		}

		// Bullets.
		bullets.move();
		bullets.detectCollisions(enemies, usersTank);

		if (checkLives())
		{
			sf::Time time = gameTime.getElapsedTime();

			GameOver gameOver(statistics, recordsFile);
			gameOver.show(window);

			recordsFile.writeMaxScore(statistics.score);
			recordsFile.writeTime(time.asSeconds());

			restartTime(enemiesSpawnTime, enemiesMoveTime, enemiesFireTime, planeSpawnTime, planeMoveTime, planeFireTime);

			try
			{
				restart();
			}
			catch (const std::exception & ex)
			{
				MessageBox(NULL, ex.what(), "Error", MB_OK);
				exit(0);
			}
		}

		update(window);
	}
}

void single_player::SinglePlayer::eventLoop(sf::RenderWindow & window)
{
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
				if (enemies.isEmptyPosition(sf::Vector2f(usersTank.getPosition().x - 35.5f, 215.1f)))
					usersTank.moveLeft();
				break;
			case sf::Keyboard::Right:
				if (enemies.isEmptyPosition(sf::Vector2f(usersTank.getPosition().x + 35.5f, 215.1f)))
					usersTank.moveRight();
				break;
			}
			break;
		case sf::Event::KeyReleased:
			switch (_event.key.code)
			{
			case sf::Keyboard::Space:
				sf::Vector2f position = usersTank.getPosition();
				bullets.pushBack(std::shared_ptr<Bullet>(new Bullet("resources/bullet.png", position.x + 7.3f, position.y - 3.f, Bullet::Direction::DIRECTION_UP)));
				break;
			}
			break;
		}
	}
}

void single_player::SinglePlayer::drawEntities(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(usersTank);
	window.draw(bullets);
	window.draw(enemies);
	window.draw(scoreText);

	if (plane.isExist())
		window.draw(plane);

	window.display();
}

bool single_player::SinglePlayer::checkLives()
{
	if (usersTank.getLives() <= 0)
		return true;

	enemies.checkLives(statistics);

	return false;
}

void single_player::SinglePlayer::restart()
{
	enemies.destroyAll();
	bullets.destroyAll();

	usersTank.dislocate();
	usersTank.setLives(3);

	statistics.reset();

	plane.setExist(false);

	try
	{
		loadBg();
	}
	catch (const std::exception & ex)
	{
		throw;
	}
}

void single_player::SinglePlayer::updateScoreText()
{
	if (atoi(std::string(scoreText.getString()).c_str()) != statistics.score)
	{
		scoreText.setString(std::to_string(statistics.score));
	}
}

void single_player::SinglePlayer::update(sf::RenderWindow & window)
{
	updateScoreText();
	updateTitle(window);
}

void single_player::SinglePlayer::restartTime(sf::Clock & c0, sf::Clock & c1, sf::Clock & c2, sf::Clock & c3, sf::Clock & c4, sf::Clock & c5)
{
	c0.restart();
	c1.restart();
	c2.restart();
	c3.restart();
	c4.restart();
	c5.restart();

	gameTime.restart();
}