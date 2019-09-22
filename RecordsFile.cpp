#include "RecordsFile.h"
using namespace tank_battle;

std::string RecordsFile::scoreFile = "files/score_record.txt";
std::string RecordsFile::timeFile = "files/time_record.txt";

void RecordsFile::writeMaxScore(int score)
{
	if (score <= getMaxScore())
		return;

	std::fstream fs(scoreFile, std::ios::out);

	try
	{
		if (!fs.is_open())
			throw std::logic_error("Can not open the file" + scoreFile);
	}
	catch (const std::exception & ex)
	{
		MessageBox(NULL, ex.what(), "Error", MB_OK);
		exit(0);
	}

	fs << score;

	fs.close();
}

void RecordsFile::writeTime(float time)
{
	if (time <= getTime())
		return;

	std::fstream fs(timeFile, std::ios::out);

	try
	{
		if (!fs.is_open())
			throw std::logic_error("Can not open the file" + timeFile);
	}
	catch (const std::exception & ex)
	{
		MessageBox(NULL, ex.what(), "Error", MB_OK);
		exit(0);
	}
	fs << time;

	fs.close();
}

int RecordsFile::getMaxScore() 
{
	std::fstream fs(scoreFile, std::ios::in);

	if (!fs.is_open())
		return 0;

	int temp;

	fs >> temp;

	fs.close();

	return temp;
}

float RecordsFile::getTime()
{
	std::fstream fs(timeFile, std::ios::in);

	if (!fs.is_open())
		return 0.f;

	float temp;

	fs >> temp;

	fs.close();

	return temp;
}
