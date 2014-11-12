#include "ResourceManager.h"
#include "InputHandler.h"
#include "Level.h"
#include "HighScore.h"

#ifndef GAME_H
#define GAME_H

class Game 
{
 public:
 Game(InputHandler* inputHandler, ResourceManager* rm, HighScore* highScore) : _inputHandler{inputHandler}, _rm{rm}, _highScore{highScore} 
  {
    _level = new Level(inputHandler, rm);
  }
  
 void run();
 bool isPaused() { return _paused; } 

 private:
  InputHandler* _inputHandler;
  ResourceManager* _rm;
  Level* _level;
  HighScore* _highScore;

  bool _paused;

  void handleInput();
  void updateLogic();
  void render();
};

#endif
