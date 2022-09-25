#ifndef MODULES_LOGGER_PROVIDER_H
#define MODULES_LOGGER_PROVIDER_H

#include <memory>
#include "Logger.hpp"

namespace ogl {
	namespace logger {
		class Provider
		{
		public:
			static void setLogger(std::shared_ptr<Logger> logger)
			{
				m_logger = logger;
			}
			static std::shared_ptr<Logger> logger()
			{
				return m_logger;
			}

		private:
			inline static std::shared_ptr<Logger> m_logger;
		};
	}
}
#endif
