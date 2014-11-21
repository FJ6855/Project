#include "Level.h"
#include "LevelSegment.h"

#include <iostream>

void Level::loadLevel()
{
	loadSegments();

	//TODO: call playerRenderer->loadContent()
}

void Level::loadSegments()
{
	//TODO: load all segments into loadedSegments
	for (int i{ 0 }; i < 5; ++i)
	{
		LevelSegment* ls = new LevelSegment(_rm);
		ls->loadLevelSegment("levelSegment" + std::to_string(i));
		_loadedSegments.push_back(ls);
	}

	int random = _rnd() % (_loadedSegments.size() - 1);
	
	_segments.push_back(new LevelSegment(*(_loadedSegments.at(0))));
	_segments.push_back(new LevelSegment(*(_loadedSegments.at(random))));
	_segments.push_back(new LevelSegment(*(_loadedSegments.at(random))));
}

void Level::handleInput()
{
	_player->handleInput(_input);
}

void Level::updateLogic()
{
	_player->updateLogic();

	if (_player->getX() >= 897)
	{
		_player->setX(_player->getX() - 897);
		delete _segments.at(0); //Free the memory
		_segments.at(0) = _segments.at(1);
		_segments.at(1) = _segments.at(2);
		int random = _rnd() % _loadedSegments.size();
		_segments.at(2) = new LevelSegment(*(_loadedSegments.at(random)));
	} 

	if (_player->getState() == PlayerState::dead)
	{
		reset();
	}

	//TODO change difficulty and do _player->setDifficulty(x);
}

void Level::render(SDL_Renderer* renderer)
{
	if (_background->getX() <= -896) _background->setX(0);

	_background->setX(_background->getX() + -_player->getXvel() / _player->getSpeed());
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
  _player->setY(256);
  _player->setState(PlayerState::inAir);
  _player->setXvel(0);
  _player->setYvel(0);
  _player->setScore(0);
  _player->setHealth(100);

  int random = _rnd() % (_loadedSegments.size() - 1);

  delete _segments.at(0); //Free the memory
  delete _segments.at(1); //Free the memory
  delete _segments.at(2); //Free the memory

  _segments.at(0) = new LevelSegment(*(_loadedSegments.at(0)));
  _segments.at(1) = new LevelSegment(*(_loadedSegments.at(random)));
  _segments.at(2) = new LevelSegment(*(_loadedSegments.at(random)));

  _activeSegmentIndex = 0;
}

PlayerState Level::getPlayerState()
{
  return _player->getState();
}
