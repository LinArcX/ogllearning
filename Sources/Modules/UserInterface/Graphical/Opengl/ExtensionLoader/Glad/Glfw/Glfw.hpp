#ifndef USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLAD_GLFW_H
#define USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLAD_GLFW_H

#include "../../ExtensionLoader.hpp"

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace extensionLoader {
					namespace glad {
						namespace glfw {
							class Glfw : public ExtensionLoader
							{
							public:
								Glfw() { ; }
								~Glfw() { ; }
								virtual void initialize() override;
							};
						}
					}
				}
			}
		}
	}
}

#endif

