#ifndef LOGGER_MANAGER_CONSOLE_H
#define LOGGER_MANAGER_CONSOLE_H

#include "logger_manager.hpp"

namespace ogl {
	class LoggerManagerConsole : public LoggerManager
	{
	public:
		LoggerManagerConsole();
		~LoggerManagerConsole();

		void trace(std::string text_log) override;
		void debug(std::string text_log) override;
		void info(std::string text_log) override;
		void warn(std::string text_log) override;
		void error(std::string text_log) override;
		void fatal(std::string text_log) override;
	};
}
#endif
