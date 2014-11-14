#include "ResourceManager.h"
#include "InputHandler.h"
#include "Level.h"
#include "SystemModule.h"
#include "HighScore.h"

#ifndef GAME_H
#define GAME_H

class Game : public SystemModule
{
 public:
	 Game(InputHandler* input, ResourceManager* rm, HighScore* highScore, SDL_Renderer* renderer) : SystemModule{}, _input{ input }, _rm{ rm }, _highScore{ highScore }, _renderer{ renderer }
  {
    _level = new Level(input, rm);
  }
  
 void run();
 SystemState getState();

 private:
  InputHandler* _input;
  ResourceManager* _rm;
  Level* _level;
  HighScore* _highScore;
  SDL_Renderer* _renderer;
  void handleInput();
  void updateLogic();
  void render();
};

#endif
