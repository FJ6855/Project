#include <vector>
#include <random>

#include "InputHandler.h"
#include "ResourceManager.h"
#include "LevelSegment.h"
#include "Player.h"
#include "PlayerRenderer.h"
#include "Background.h"
#include "BackgroundRenderer.h"

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
  public:
	Level(InputHandler* input, ResourceManager* rm) : _input{input}, _rm{rm} 
	{
		_player = new Player(-896, 200, 32, 32);
		_playerRenderer = new PlayerRenderer(rm);
		_backgroundRenderer = new BackgroundRenderer(rm);
		_background = new Background();
		_currentDifficulty = 1;
		_maxDifficulty = 10;
		_player->setDifficulty(_currentDifficulty);
		_activeSegmentIndex = 0;
		loadLevel();
	}
 
	void handleInput();
	void updateLogic();
	void render(SDL_Renderer* renderer);
	void handleCollision();
	Player* getPlayer() { return _player; }
	PlayerState getPlayerState();
	void reset();

  private:
	void loadLevel();
	void loadSegments();
	int getRandom();

	InputHandler* _input;
	ResourceManager* _rm;

	std::random_device _rnd;

	std::vector<LevelSegment*> _segments;
	std::vector<LevelSegment*> _loadedSegments;

	int _activeSegmentIndex;
	int _currentDifficulty;
	int _maxDifficulty;

	Player* _player;
	PlayerRenderer* _playerRenderer;

	Background* _background;
	BackgroundRenderer* _backgroundRenderer;
};

#endif
