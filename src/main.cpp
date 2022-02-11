#include "game.hpp"

#include "extension_loader/extension_loader_glad_glfw.hpp"
#include "extension_loader/extension_loader_glad_sdl.hpp"

#include "window_manager/window_manager_glfw.hpp"
#include "window_manager/window_manager_sdl.hpp"

int main(int argc, char* args[])
{
	//ExtensionLoaderGladGlfw extension_loader;
	ExtensionLoaderGladSdl extension_loader;

	//WindowManagerGLFW window_manager;
	WindowManagerSDL window_manager;

	Game game(extension_loader, window_manager);
	game.run();
	return 0;
}
