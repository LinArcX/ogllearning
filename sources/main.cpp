#include "modules/config_manager/config_manager_provider.hpp"
#include "modules/config_manager/config_manager_pc.hpp"

#include "modules/logger_manager/logger_manager_provider.hpp"
#include "modules/logger_manager/logger_manager_console.hpp"

#include "modules/game_manager/game_manager.hpp"
#include "modules/game_manager/opengl/game_manager_opengl.hpp"

#include "modules/game_manager/opengl/extension_loader/extension_loader_glad_glfw.hpp"
#include "modules/game_manager/opengl/extension_loader/extension_loader_glad_sdl.hpp"

#include "modules/game_manager/opengl/window_manager/window_manager.hpp"
#include "modules/game_manager/opengl/window_manager/window_manager_glfw.hpp"
#include "modules/game_manager/opengl/window_manager/window_manager_sdl.hpp"

void prepareConfigManager()
{
	std::shared_ptr<ogl::ConfigManager> configManagerPc =
		std::shared_ptr<ogl::ConfigManagerPc>();

	ogl::ConfigManagerProvider::setConfigManager(configManagerPc);
}

void prepareLoggerManager()
{
	std::shared_ptr<ogl::LoggerManager> loggerManagerConsole =
		std::shared_ptr<ogl::LoggerManagerConsole>();

	ogl::LoggerManagerProvider::setLoggerManager(loggerManagerConsole);
}

void prepareGameManager()
{
	// replace these with builder pattern or strategy pattern
	std::shared_ptr<IExtensionLoader> extensionLoaderGladSDL =
		std::make_shared<ExtensionLoaderGladSdl>();

	std::shared_ptr<IExtensionLoader> extensionLoaderGladGlfw =
		std::make_shared<ExtensionLoaderGladGlfw>();

	std::shared_ptr<IWindowManager> windowManagerSDL =
		std::make_shared<WindowManagerSDL>();

	std::unique_ptr<GameManager> gameManagerOpenGL =
		std::make_unique<GameManagerOpenGL>(extensionLoaderGladGlfw, windowManagerSDL);

	gameManagerOpenGL->run();
}

int main(int argc, char* args[])
{
	prepareConfigManager();
	prepareLoggerManager();
	prepareGameManager();
	return 0;
}
