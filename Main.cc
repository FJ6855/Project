#include <iostream>

#include "SDL/SDL.h"
#include "Game.h"

using namespace std;

enum MainState
  {
    GameState,
    MenuState,
  };

int main(int argc, char* argv[])
{
  MainState mainState = GameState;

  InputHandler* input = new InputHandler();
  ResourceManager* rm = new ResourceManager();
  HighScore* highScore = new HighScore();

  Game* game = new Game(input, rm, highScore);

  while (true)
    {
      if (mainState == GameState)
	{
	  game->run();
	}
      else if (mainState == MenuState)
	{
	  // TODO: MenuSystem
	}
    }

  return 0;
}
