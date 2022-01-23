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

#include <iostream>
#include <string>
#include <stdio.h>

enum class GameState {PLAY, EXIT};

class MainGame
{
  int p_screenWidth;
  int p_screenHeight;
  SDL_Window* p_window = NULL;
  SDL_Surface* p_screen_surface = NULL;
  SDL_Surface* p_img_hello_world = NULL;
  GameState p_game_state;

  void init();
  void game_loop();
  void process_input();
  void load_media();
  void close();

  template <typename T>
  void fatal(T t);

  template<typename T, typename... Args>
  void fatal(T t, Args... args); // recursive variadic function
  
public:
  MainGame();
  ~MainGame();

  void run();
};
#endif
