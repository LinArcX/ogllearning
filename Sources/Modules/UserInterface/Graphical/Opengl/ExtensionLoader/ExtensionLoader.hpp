#ifndef USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_H
#define USERINTERFACE_GRAPHICAL_OPENGL_EXTENSION_LOADER_H

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				namespace extensionLoader {
					class ExtensionLoader
					{
					public:
						virtual ~ExtensionLoader() { ; }
						virtual void initialize() = 0;
					};
				}
			}
		}
	}
}

#endif

