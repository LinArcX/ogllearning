#ifndef USERINTERFACE_GRAPHICAL_OPENGL_LIFECYCLE_H
#define USERINTERFACE_GRAPHICAL_OPENGL_LIFECYCLE_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <memory>

#include "../Window.hpp"
#include "Program/Glsl.hpp"
#include "../../LifeCycle.hpp"
#include "ingredients/sprite.hpp"
#include "ExtensionLoader/ExtensionLoader.hpp"

using namespace ogl::userInterface::graphical::opengl::program;
using namespace ogl::userInterface::graphical::opengl::ingredients;
using namespace ogl::userInterface::graphical::opengl::extensionLoader;

namespace ogl {
	namespace userInterface {
		namespace graphical {
			namespace opengl {
				class LifeCycle : public ogl::userInterface::LifeCycle
				{
				public:
					LifeCycle(std::shared_ptr<ExtensionLoader> extensionLoader,
						std::shared_ptr<Window> window);
					~LifeCycle();

					void initialize() override;
					void draw() override;
					void loop() override;
					void run() override;

				private:
					void initializeShaders();
					void print_version();

				private:
					float m_time = 0;
					Sprite m_sprite;
					Program m_color_program;
					std::shared_ptr<ExtensionLoader> m_extension_loader;
					std::shared_ptr<Window> m_window;
				};
			}
		}
	}
}
#endif
