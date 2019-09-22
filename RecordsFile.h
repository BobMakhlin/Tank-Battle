#pragma once
#include <string>
#include <fstream>
#include <Windows.h>

namespace tank_battle
{
	class RecordsFile
	{
	private:
		static std::string scoreFile;
		static std::string timeFile;
	public:
		static void writeMaxScore(int);
		static void writeTime(float);
		static int getMaxScore();
		static float getTime();
	};
}
