#ifndef MODULED_LOGGER_CONSOLE_H
#define MODULED_LOGGER_CONSOLE_H

#include "../Logger.hpp"

namespace ogl {
	namespace logger {
		namespace console {
			class Console : public Logger
			{
			public:
				Console();
				~Console();

				void trace(std::string text_log) override;
				void debug(std::string text_log) override;
				void info(std::string text_log) override;
				void warn(std::string text_log) override;
				void error(std::string text_log) override;
				void fatal(std::string text_log) override;
			};
		}
	}
}
#endif
