#include "MainGame.h"

MainGame::MainGame()
{
    screenWidth = 640;
    screenHeight = 480;
}

MainGame::~MainGame()
{

}

bool MainGame::init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    window = SDL_CreateWindow("SDL Tutorial",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                screenWidth, screenHeight, SDL_WINDOW_OPENGL);
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

bool MainGame::load_media()
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

void MainGame::run()
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
      SDL_BlitSurface(img_hello_world, NULL, screen_surface, NULL);
      SDL_UpdateWindowSurface(window);
      SDL_Delay(2000);
    }
  }
  close();
}

void MainGame::close()
{
  SDL_FreeSurface(img_hello_world);
  img_hello_world = NULL;
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}

