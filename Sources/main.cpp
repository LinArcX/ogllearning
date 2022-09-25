#include "modules/Configurations/Provider.hpp"
#include "modules/Configurations/Pc.hpp"

#include "modules/Logger/Provider.hpp"
#include "modules/Logger/Console/Console.hpp"

#include "modules/UserInterface/Graphical/Window.hpp"
#include "modules/UserInterface/LifeCycle.hpp"
#include "modules/UserInterface/Graphical/Opengl/LifeCycle.hpp"

#include "modules/UserInterface/Graphical/Opengl/ExtensionLoader/Glad/Glfw/Glfw.hpp"
#include "modules/UserInterface/Graphical/Opengl/ExtensionLoader/Glad/Sdl/GladSdl.hpp"

#include "modules/UserInterface/Graphical/Opengl/Window/Glfw/Glfw.hpp"
#include "modules/UserInterface/Graphical/Opengl/Window/Sdl/Sdl.hpp"

// replace these with builder pattern or strategy pattern
void setupConfigurations()
{
	using namespace ogl::configurations;

	std::shared_ptr<Configurations> configurationsPc = std::make_shared<Pc>();
	Provider::setProvider(configurationsPc);
}

void setupLogger()
{
	using namespace ogl::logger;

	std::shared_ptr<Logger> loggerConsole = std::make_shared<console::Console>();
	Provider::setLogger(loggerConsole);
}

std::unique_ptr<ogl::userInterface::LifeCycle> game;

void setupGame()
{
	//using namespace ogl::userInterface::graphical;
	//using namespace ogl::userInterface::graphical::opengl::extensionLoader;

	std::shared_ptr<ExtensionLoader> extensionLoader = std::make_shared<glad::sdl::Sdl>();
	//std::shared_ptr<ExtensionLoader> extensionLoaderGladGlfw = std::make_shared<glad::glfw::Glfw>();

	std::shared_ptr<ogl::userInterface::graphical::Window> window
		= std::make_shared<ogl::userInterface::graphical::Sdl>();
	game = std::make_unique<ogl::userInterface::graphical::opengl::LifeCycle>(extensionLoader, window);
}

void runGame() {
	game->run();
}

int main(int argc, char* args[])
{
	setupConfigurations();
	setupLogger();
	setupGame();
	runGame();

	return 0;
}
