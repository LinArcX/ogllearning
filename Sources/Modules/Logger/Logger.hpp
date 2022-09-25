#ifndef MODULES_LOGGER_H
#define MODULES_LOGGER_H

#include <string>

namespace ogl {
	namespace logger {
		class Logger
		{
		public:
			virtual ~Logger() { ; }

			virtual void trace(std::string) = 0;
			virtual void debug(std::string) = 0;
			virtual void info(std::string) = 0;
			virtual void warn(std::string) = 0;
			virtual void error(std::string) = 0;
			virtual void fatal(std::string) = 0;
		};
	}
}
#endif
