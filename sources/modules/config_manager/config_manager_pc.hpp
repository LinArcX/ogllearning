#ifndef CONFIG_MANAGER_PC_H
#define CONFIG_MANAGER_PC_H

#include "config_manager.hpp"

namespace ogl {
	class ConfigManagerPc : public  ConfigManager
	{
		std::string getAppName() override { return "Learn OpenGL"; }
		uint16_t getAppWidth() override { return 640; }
		uint16_t getAppHeight() override { return 480; }
	};
}
#endif
