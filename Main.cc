#include <iostream>
#include "SDL2/SDL.h"

enum MainState
{
    GameState,
    MenuState,
    
};

#include "Game.h"

using namespace std;

const int SCREEN_WIDTH = 896;
const int SCREEN_HEIGHT = 512;

bool init();
void drawGame();
void clearScreen();

SDL_Renderer* gRenderer = nullptr;
SDL_Window* gWindow = nullptr;

int main(int argc, char* argv[])
{

  MainState state = GameState;

  InputHandler* input = new InputHandler();
  ResourceManager* rm = new ResourceManager();
  HighScore* highScore = new HighScore();
  Game* game = new Game(input, rm, highScore);

  if(!init())
  {
    return 1;
  }

  while (!input->isQuit())
    {
      input->update();

      clearScreen();

      if (state == GameState)
	{
	   game->run();
	   //if(game->isPaused())
	   //{
	   // menuSystem->setMenuState(MenuState::PauseMenu);
	   // state = Menu;
	   //}
	}
      else if (state == MenuState)
	{
	  //TODO: MenuSystem
	  //menuSystem->run();
	}

      drawGame();
    
    }

  return 0;
}

void drawGame()
{
  SDL_RenderPresent(gRenderer);
}

void clearScreen()
{
  SDL_RenderClear(gRenderer);
}

bool init()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      printf("SDL could not initialize SDL_Error: %s\n", SDL_GetError());
      return false;
    }
  //Create Window
  gWindow = SDL_CreateWindow("SaftEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (gWindow == NULL)
    {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      return false;
    }
  //Create renderer for window
  gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gRenderer == NULL)
    {
      printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
      return false;
    }
  //Initialize renderer color
  SDL_SetRenderDrawColor(gRenderer, 0x0, 0x0, 0x0, 0xFF);

  return true;
}
