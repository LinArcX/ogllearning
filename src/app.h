#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
void close();
bool load_media();

// The window we'll be rendering to
SDL_Window* window = NULL;
// The surface contained by the window
SDL_Surface* screen_surface = NULL;
// The image we will load and show on the screen
SDL_Surface* img_hello_world = NULL;
