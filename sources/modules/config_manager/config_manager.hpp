#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <cstdint>

namespace ogl {
	class ConfigManager
	{
	public:
		virtual std::string getAppName() = 0;
		virtual uint16_t getAppWidth() = 0;
		virtual uint16_t getAppHeight() = 0;
	};
}
#endif
