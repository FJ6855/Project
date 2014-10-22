#include <iostream>

using namespace std;

enum MainState
  {
    Game,
    MenuSystem,
  };

int main(int argc, char[]* argv)
{
  InputHandler* inputHandler = new InputHandler();
  ResourceManager* rm = new ResourceManager();

  Game* game = new Game();
  
  MainState mainState;
  
  while (true)
    {
      if (mainState == Game)
	{
	  game->run();
	}
    }

  return 0;
}
