#ifndef LOGGER_MANAGER_H
#define LOGGER_MANAGER_H

#include <string>

namespace ogl {
	class LoggerManager
	{
	public:
		virtual ~LoggerManager() { ; }

		virtual void trace(std::string) = 0;
		virtual void debug(std::string) = 0;
		virtual void info(std::string) = 0;
		virtual void warn(std::string) = 0;
		virtual void error(std::string) = 0;
		virtual void fatal(std::string) = 0;
	};
}
#endif
