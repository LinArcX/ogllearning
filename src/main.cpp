#include "SDL_cpuinfo.h"
#include "app.h"
#include <GL/glew.h>
#include <cstdio>
#include <SDL_assert.h>
#include <stdio.h>

bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      success = false;
    }
    else
    {
      screen_surface = SDL_GetWindowSurface(window);
    }
  }
  return success;
}

bool load_media()
{
  bool success = true;
  img_hello_world = SDL_LoadBMP("image.bmp");
  if (img_hello_world == NULL)
  {
    printf("Unable to load image %s! SDL Error: %s\n", "image.bmp", SDL_GetError());
    success = false;
  }
  return success;
}

void close()
{
  // Deallocate surface
  SDL_FreeSurface(img_hello_world);
  img_hello_world = NULL;
  // Destroy window
  SDL_DestroyWindow(window);
  window = NULL;
  // Quit SDL subsystems
  SDL_Quit();
}

int main(int argc, char* args[])
{
  if (!init()) {
    printf("Failed to initialize!\n");
  }
  else
  {
    if (!load_media())
    {
      printf("Failed to load media!\n");
    }
    else
    {
      // Apply the image
      SDL_BlitSurface(img_hello_world, NULL, screen_surface, NULL);
      // Update the surface
      SDL_UpdateWindowSurface(window);
      // Wait two seconds
      SDL_Delay(2000);
    }
  }
  // Free resources and close SDL
  close();
  return 0;
}
