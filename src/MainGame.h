#ifndef MAIN_GAME_H
#define MAIN_GAME

#ifdef _WIN32 // note the underscore: without it, it's not msdn official!
  // Windows (x64 and x86)
  #include <Windows.h>
  #include <SDL/SDL.h>
  #include <SDL/SDL_cpuinfo.h>
  #include <SDL/SDL_video.h>
  #include <SDL/SDL_assert.h>
#elif __linux__
  #include <SDL.h>
  #include <SDL_cpuinfo.h>
  #include <SDL_video.h>
  #include <SDL_assert.h>
#endif

#include <GL/glew.h>

#include <stdio.h>

class MainGame
{
public:
    MainGame();
    ~MainGame();

    bool init();
    void close();
    bool load_media();
    void run();

private:
    int screenWidth;
    int screenHeight;
    SDL_Window* window = NULL;
    SDL_Surface* screen_surface = NULL;
    SDL_Surface* img_hello_world = NULL;
};
#endif
