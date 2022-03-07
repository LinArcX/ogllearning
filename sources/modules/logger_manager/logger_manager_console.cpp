#include "logger_manager_console.hpp"

#include <iostream>

ogl::LoggerManagerConsole::LoggerManagerConsole()
{
}

ogl::LoggerManagerConsole::~LoggerManagerConsole()
{
}

void ogl::LoggerManagerConsole::trace(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void ogl::LoggerManagerConsole::debug(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void ogl::LoggerManagerConsole::info(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void ogl::LoggerManagerConsole::warn(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void ogl::LoggerManagerConsole::error(std::string text_log)
{
	std::cout << text_log << std::endl;
}

void ogl::LoggerManagerConsole::fatal(std::string text_log)
{
	std::cout << text_log << std::endl;
	throw "fatal error occured!";
}
