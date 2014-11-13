#include "ResourceManager.h"
#include "InputHandler.h"
#include "Level.h"
#include "HighScore.h"

#ifndef GAME_H
#define GAME_H

class Game 
{
 public:
 Game(InputHandler* input, ResourceManager* rm, HighScore* highScore) : _input{input}, _rm{rm}, _highScore{highScore} 
  {
    _level = new Level(input, rm);
  }
  
 void run();
 bool isPaused() { return _paused; } 

 private:
  InputHandler* _input;
  ResourceManager* _rm;
  Level* _level;
  HighScore* _highScore;

  bool _paused;

  void handleInput();
  void updateLogic();
  void render();
};

#endif
