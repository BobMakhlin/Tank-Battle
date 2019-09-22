#include "GameOver.h"
using namespace tank_battle;

single_player::GameOver::GameOver(const Statistics & statistics, const RecordsFile & recordsFile)
	:
	GameView("resources/game_over/game_over.jpg"),
	buttonPlay("resources/game_over/play_button.png", sf::Vector2f(101.f, 100.f)),
	buttonExit("resources/game_over/exit_button.png", sf::Vector2f(93.f, 93.f))
{
	buttonPlay.setPosition(sf::Vector2f(102.f, 379.5f));
	buttonExit.setPosition(sf::Vector2f(232.f, 380.f));

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

	score.setFont(font);
	score.setCharacterSize(20);
	score.setFillColor(sf::Color(219, 187, 87));
	score.setString("Score: " + std::to_string(statistics.score) +
		", Record score: " + std::to_string(recordsFile.getMaxScore()));
	score.setPosition(sf::Vector2f(85.f, 220.f));

	bestTime.setFont(font);
	bestTime.setCharacterSize(20);
	bestTime.setFillColor(sf::Color(219, 187, 87));
	bestTime.setString("Best time: " + std::to_string(recordsFile.getTime()));
	bestTime.setPosition(sf::Vector2f(118.f, 260.f));

	tanksDestroyed.setFont(font);
	tanksDestroyed.setCharacterSize(20);
	tanksDestroyed.setFillColor(sf::Color(219, 187, 87));
	tanksDestroyed.setString("Enemy tanks destroyed: " + std::to_string(statistics.tanksDestroyed));
	tanksDestroyed.setPosition(sf::Vector2f(95.f, 300.f));

	soldiersDestroyed.setFont(font);
	soldiersDestroyed.setCharacterSize(20);
	soldiersDestroyed.setFillColor(sf::Color(219, 187, 87));
	soldiersDestroyed.setString("Enemy soldiers destroyed: " + std::to_string(statistics.soldiersDestroyed));
	soldiersDestroyed.setPosition(sf::Vector2f(85.f, 340.f));
}

void single_player::GameOver::gameLoop(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		if (eventLoop(window))
			return;

		drawEntities(window);
	}
}

bool single_player::GameOver::eventLoop(sf::RenderWindow & window)
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (_event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttonPlay.isClicked(_event.mouseButton.x, _event.mouseButton.y))
					return true; // Exit.
				else if (buttonExit.isClicked(_event.mouseButton.x, _event.mouseButton.y))
					window.close();
			}
			break;
		case sf::Event::Closed:
			window.close();
		}
	}
	return false;
}

void single_player::GameOver::drawEntities(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(buttonPlay);
	window.draw(buttonExit);

	window.draw(score);
	window.draw(soldiersDestroyed);
	window.draw(tanksDestroyed);
	window.draw(bestTime);

	window.display();
}

duo_player::GameOver::GameOver()
	: GameView("resources/game_over/game_over.jpg"),
	buttonPlay("resources/game_over/play_button.png", sf::Vector2f(101.f, 100.f)),
	buttonExit("resources/game_over/exit_button.png", sf::Vector2f(93.f, 93.f))
{
	buttonPlay.setPosition(sf::Vector2f(102.f, 379.5f));
	buttonExit.setPosition(sf::Vector2f(232.f, 380.f));

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

	info.setFont(font);
	info.setCharacterSize(24);
	info.setFillColor(sf::Color(219, 187, 87));
	info.setPosition(sf::Vector2f(120, 270));
}

void single_player::GameOver::show(sf::RenderWindow & window)
{
	gameLoop(window);
}

void duo_player::GameOver::gameLoop(sf::RenderWindow & window)
{
	while (window.isOpen())
	{
		if (eventLoop(window))
			return;

		drawEntities(window);
	}
}

bool duo_player::GameOver::eventLoop(sf::RenderWindow & window)
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (_event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttonPlay.isClicked(_event.mouseButton.x, _event.mouseButton.y))
					return true; // Exit.
				else if (buttonExit.isClicked(_event.mouseButton.x, _event.mouseButton.y))
					window.close();
			}
			break;
		case sf::Event::Closed:
			window.close();
		}
	}
	return false;
}

void duo_player::GameOver::drawEntities(sf::RenderWindow & window)
{
	window.clear();

	window.draw(background);
	window.draw(buttonPlay);
	window.draw(buttonExit);
	window.draw(info);

	window.display();
}

void duo_player::GameOver::show(sf::RenderWindow & window)
{
	gameLoop(window);
}

void duo_player::GameOver::setText(const std::string & t)
{
	info.setString(t);
}
