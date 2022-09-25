#ifndef CONFIGURATIONS_PROVIDER_H
#define CONFIGURATIONS_PROVIDER_H

#include <memory>
#include "configurations.hpp"

namespace ogl {
	namespace configurations {
		class Provider
		{
		public:
			inline static void setProvider(std::shared_ptr<Configurations> configurations)
			{
				m_configurations = configurations;
			}
			inline static std::shared_ptr<Configurations> provider()
			{
				return m_configurations;
			}

		private:
			inline static std::shared_ptr<Configurations> m_configurations;
		};
	}
}
#endif
