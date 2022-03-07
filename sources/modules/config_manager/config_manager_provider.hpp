#ifndef CONFIG_MANAGER_PROVIDER_H
#define CONFIG_MANAGER_PROVIDER_H

#include <memory>
#include "config_manager.hpp"

namespace ogl {
	class ConfigManagerProvider
	{
	public:
		inline static void setConfigManager(std::shared_ptr<ConfigManager> configManager)
		{
			m_configManager = configManager;
		}
		inline static std::shared_ptr<ConfigManager> getConfigManager()
		{
			return m_configManager;
		}
	private:
		inline static std::shared_ptr<ConfigManager> m_configManager;
	};
}
#endif
