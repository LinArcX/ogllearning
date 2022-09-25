#ifndef CONFIGURATIONS_PC_H
#define CONFIGURATIONS_PC_H

#include "configurations.hpp"

namespace ogl {
	namespace configurations {
		class Pc : public  Configurations
		{
		public:
			uint16_t applicationWidth() override { return 640; }
			uint16_t applicationHeight() override { return 480; }
		};
	}
}
#endif
