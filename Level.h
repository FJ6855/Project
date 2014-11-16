#include <vector>

#include "InputHandler.h"
#include "ResourceManager.h"
#include "LevelSegment.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
  public:
	Level(InputHandler* input, ResourceManager* rm) : _input{input}, _rm{rm} 
	{
	  //_player = new Player();
	  //	_playerRenderer = new PlayerRenderer();

		_currentDifficulty = 1;
		loadLevel();
	}
 
	void handleInput();
	void updateLogic();
	void render();

	//Player* getPlayer() { return _player; }

  private:
	InputHandler* _input;
	ResourceManager* _rm;
	
	vector<LevelSegment*> _segments;
	vector<LevelSegment*> _loadedSegments;

	int _activeSegmentIndex;
	int _currentDifficulty;
	
	//Player* _player;
	//PlayerRenderer* _playerRenderer;

	void handleCollisions();
	void loadLevel();
	void loadSegments();
};

#endif
