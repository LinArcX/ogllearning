#ifndef LOGGER_MANAGER_PROVIDER_H
#define LOGGER_MANAGER_PROVIDER_H

#include <memory>
#include "logger_manager.hpp"

namespace ogl {
	class LoggerManagerProvider
	{
	public:
		static void setLoggerManager(std::shared_ptr<LoggerManager> loggerManager)
		{
			m_loggerManager = loggerManager;
		}
		static std::shared_ptr<LoggerManager> getLoggerManager()
		{
			return m_loggerManager;
		}

	private:
		inline static std::shared_ptr<LoggerManager> m_loggerManager;
	};
}
#endif
