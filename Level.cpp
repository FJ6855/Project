#include "Level.h"
#include "LevelSegment.h"

#include <algorithm>
#include <iostream>

void Level::loadLevel()
{
  loadSegments();
}

void Level::loadSegments()
{
	for (int i{0}; i < _maxDifficulty * 5 + 1; ++i)
	{
		LevelSegment* ls = new LevelSegment(_rm);
		ls->loadLevelSegment("levelSegment" + std::to_string(i));
		_loadedSegments.push_back(ls);
	}

	std::sort(_loadedSegments.begin(), _loadedSegments.end(), [](LevelSegment* ls, LevelSegment* ls2) { return ls->getDifficultyRating() < ls2->getDifficultyRating(); });

	_segments.push_back(new LevelSegment(*(_loadedSegments.at(0))));
	_segments.push_back(new LevelSegment(*(_loadedSegments.at(Level::getRandom()))));
	_segments.push_back(new LevelSegment(*(_loadedSegments.at(Level::getRandom()))));
}

void Level::handleInput()
{
	_player->handleInput(_input);
}

void Level::updateLogic()
{
  for (LevelSegment* ls : _segments)
    {
      ls->updateLogic();
    }

	_player->updateLogic();

	if (_player->getX() >= 897)
	{
		_player->setX(_player->getX() - 897);

		delete _segments.at(0); //Free the memory
		
		_segments.at(0) = _segments.at(1);
		_segments.at(1) = _segments.at(2);
	       
		_segments.at(2) = new LevelSegment(*(_loadedSegments.at(Level::getRandom())));
	} 
	
	// cap difficulty at maximum difficulty rating
	if (_player->getScore() < 5000 * _maxDifficulty)
	  _currentDifficulty = _player->getScore() / 5000 + 1;

	//Logic for background
	if (_background->getX() <= -896) _background->setX(0);
	_background->setX(_background->getX() + -_player->getXvel() / _player->getSpeed());
}

void Level::render(SDL_Renderer* renderer)
{
	_backgroundRenderer->render(_background, renderer);

	for (int i{}; i < 3; ++i)
	{
		_segments.at(i)->setX(-896 + 896*i - _player->getX());
		_segments.at(i)->render(renderer);
	}
 
    _playerRenderer->render(_player, renderer);
}

void Level::handleCollision()
{
  int x = _player->getX();

  if (_player->getState() != PlayerState::jumping)
  {
	  _player->setState(PlayerState::inAir);
  }
  
  if(x < 0)
    {
      _segments.at(0)->handleCollision(_player, 0);
      _segments.at(1)->handleCollision(_player, 1);
    }
  if(x >= 0)
    {
      _segments.at(1)->handleCollision(_player, 1);
      _segments.at(2)->handleCollision(_player, 2);
    }
}

void Level::reset()
{
  _player->setX(-896);
  _player->setY(200);
  _player->setState(PlayerState::inAir);
  _player->setXvel(0);
  _player->setYvel(0);

  if(_player->getHighscore() < _player->getScore())
    _player->setHighscore(_player->getScore());
  
  _player->setScore(0);
  _player->setHealth(100);

  _currentDifficulty = 1;

  delete _segments.at(0); //Free the memory
  delete _segments.at(1); //Free the memory
  delete _segments.at(2); //Free the memory

  _segments.at(0) = new LevelSegment(*(_loadedSegments.at(0)));
  _segments.at(1) = new LevelSegment(*(_loadedSegments.at(Level::getRandom())));
  _segments.at(2) = new LevelSegment(*(_loadedSegments.at(Level::getRandom())));

  _activeSegmentIndex = 0;
}

PlayerState Level::getPlayerState()
{
  return _player->getState();
}

int Level::getRandom()
{
  // Randomize index in interval of current difficulyty 
  // index: 1-6 is difficulty = 1, index: 7-11 is difficulty = 2 and so on...
  // index 0 is always the same start level segment (levelSegment0.txt)
  int random = _rnd() % 5 + (_currentDifficulty - 1) * 5 + 1;

  // Randomize a new number and check if player should get an easier 
  // level segment from the previous difficulty
  int random2 = _rnd() % 10;

  if (random2 == 8 && _currentDifficulty > 1)
    random = random - 5;

  return random;
}
