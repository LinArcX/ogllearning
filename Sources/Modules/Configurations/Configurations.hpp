#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <string>
#include <cstdint>

namespace ogl {
	namespace configurations {
		class Configurations
		{
		public:
			std::string applicationName() { return "Learn OpenGL"; }
			virtual uint16_t applicationWidth() = 0;
			virtual uint16_t applicationHeight() = 0;
		};
	}
}
#endif
