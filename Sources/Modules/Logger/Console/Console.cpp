#include "Console.hpp"

#include <iostream>

using namespace ogl::logger::console;

Console::Console() {}

Console::~Console() {}

void Console::trace(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void Console::debug(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void Console::info(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void Console::warn(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void Console::error(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void Console::fatal(std::string text_log)
{
	std::cout << text_log << std::endl;
	throw "fatal error occured!";
}

