#include "SplashScreen.h"
using namespace tank_battle;

SplashScreen::SplashScreen(const RecordsFile & recordsFile) 
	: GameView("resources/splash_screen.jpg")
{
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

	text.setFont(font);
	text.setString("Press a key to start");
	text.setCharacterSize(24);
	text.setPosition(100, 470);
	
	timeRecord.setFont(font);
	timeRecord.setString("Best time: " + std::to_string(recordsFile.getTime()));
	timeRecord.setFillColor(sf::Color(219, 187, 87));
	timeRecord.setCharacterSize(24);
	timeRecord.setPosition(100, 390);

	maxScore.setFont(font);
	maxScore.setString("Record score: " + std::to_string(recordsFile.getMaxScore()));
	maxScore.setCharacterSize(24);
	maxScore.setFillColor(sf::Color(219, 187, 87));
	maxScore.setPosition(115, 420);
}

void SplashScreen::gameLoop(sf::RenderWindow & window)
{
	sf::Clock clock;
	while (window.isOpen())
	{
		changeTextColor(clock.getElapsedTime());

		if (eventLoop(window))
			return;

		drawEntities(window);
	}
}

bool SplashScreen::eventLoop(sf::RenderWindow & window)
{
	sf::Event _event;
	while (window.pollEvent(_event))
	{
		switch (_event.type)
		{
		case sf::Event::KeyPressed:
			return true; // Exit.
		case sf::Event::MouseButtonPressed:
			return true; // Exit.
		case sf::Event::Closed:
			window.close();
		}
	}
	return false;
}

void SplashScreen::drawEntities(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(text);
	window.draw(maxScore);
	window.draw(timeRecord);

	window.display();
}

void SplashScreen::changeTextColor(const sf::Time & time)
{
	if (int(time.asSeconds()) % 2)
		text.setFillColor(sf::Color::Yellow);
	else
		text.setFillColor(sf::Color::White);
}

void SplashScreen::show(sf::RenderWindow & window) 
{
	gameLoop(window);
}
