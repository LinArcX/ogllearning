#include "MainGame.h"

MainGame::MainGame()
{
  p_window = nullptr;
  p_screen_surface = nullptr;
  p_img_hello_world = nullptr;
  p_screenWidth = 640;
  p_screenHeight = 480;
  p_game_state = GameState::PLAY;
}

MainGame::~MainGame()
{
}

template <typename T>
void MainGame::fatal(T t) 
{
  std::cout << t << std::endl ;
  std::cout << "Enter any key to quit...";
  int temp;
  std::cin >> temp;
  close();
}

template<typename T, typename... Args>
void MainGame::fatal(T t, Args... args) // recursive variadic function
{
  std::cout << t <<std::endl ;
  fatal(args...) ;
}

void MainGame::init()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fatal("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else
  {
    p_window = SDL_CreateWindow("SDL Tutorial",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                p_screenWidth, p_screenHeight, SDL_WINDOW_OPENGL);
    if (nullptr == p_window)
    {
      fatal("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
      p_screen_surface = SDL_GetWindowSurface(p_window);
    }
  }
}

void MainGame::game_loop()
{
  while (p_game_state != GameState::EXIT) {
    process_input();
    }
}

void MainGame::process_input()
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        p_game_state = GameState::EXIT;
          break;
      case SDL_MOUSEMOTION:
        std::cout
          << "x: " << event.motion.x
          << " ,y: " << event.motion.y
          << std::endl;
          break;
      default:
          break;
    }
  }
}

void MainGame::load_media()
{
  p_img_hello_world = SDL_LoadBMP("image.bmp");
  if (!p_img_hello_world)
  {
    fatal("Unable to load image %s! SDL Error: %s\n", "image.bmp", SDL_GetError());
  }
}

void MainGame::run()
{
  init();
  game_loop();
  //if (!load_media())
  //{
  //  printf("Failed to load media!\n");
  //}
  //else
  //{
  //  SDL_BlitSurface(p_img_hello_world, NULL, p_screen_surface, NULL);
  //  SDL_UpdateWindowSurface(p_window);
  //  SDL_Delay(2000);
  //}
  close();
}

void MainGame::close()
{
  SDL_FreeSurface(p_img_hello_world);
  p_img_hello_world = NULL;
  SDL_DestroyWindow(p_window);
  p_window = NULL;
  SDL_Quit();
}
