#pragma once
#include <stdexcept>
#include <string>

namespace tank_battle
{
	class load_error : public std::exception
	{
	public:
		explicit load_error(const std::string & _Message)
			: exception(_Message.c_str())
		{
		}

		explicit load_error(const char * _Message)
			: exception(_Message)
		{
		}
	};
}
