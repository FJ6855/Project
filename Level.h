#include <vector>
#include <random>

#include "InputHandler.h"
#include "ResourceManager.h"
#include "LevelSegment.h"
#include "Player.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
  public:
	Level(InputHandler* input, ResourceManager* rm) : _input{input}, _rm{rm} 
	{
		_currentDifficulty = 1;
		_activeSegmentIndex = 0;
		loadLevel();

		_player = new Player(-896, 256, 32, 32);
		//_playerRenderer = new PlayerRenderer();
	}
 
	void handleInput();
	void updateLogic();
	void render(SDL_Renderer* renderer);

	//Player* getPlayer() { return _player; }

  private:
	void handleCollisions();
	void loadLevel();
	void loadSegments();

	InputHandler* _input;
	ResourceManager* _rm;

	std::random_device _rnd;

	std::vector<LevelSegment*> _segments;
	std::vector<LevelSegment*> _loadedSegments;

	int _activeSegmentIndex;
	int _currentDifficulty;

	Player* _player;
	//PlayerRenderer* _playerRenderer;
};

#endif
