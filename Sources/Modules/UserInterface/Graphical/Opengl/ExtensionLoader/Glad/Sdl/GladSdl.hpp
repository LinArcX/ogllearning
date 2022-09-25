#ifndef USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLAD_SDL_H
#define USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_GLAD_SDL_H

#include "../../ExtensionLoader.hpp"

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace extensionLoader {
					namespace glad {
						namespace sdl {
							class Sdl : public ExtensionLoader
							{
							public:
								//Sdl() { ; }
								//~Sdl() { ; }
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
