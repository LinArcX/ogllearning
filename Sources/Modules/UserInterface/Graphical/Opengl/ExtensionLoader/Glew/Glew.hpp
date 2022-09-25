#ifndef USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLEW_H
#define USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLEW_H

#include "../../ExtensionLoader/ExtensionLoader.hpp"

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace extensionLoader {
					namespace glew {
						class Glew : public ExtensionLoader
						{
						public:
							void initialize() override;
						};
					}
				}
			}
		}
	}
}
#endif
