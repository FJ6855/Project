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

	_segments.push_back(_loadedSegments.at(random));
	_segments.push_back(_loadedSegments.at(random));
	_segments.push_back(_loadedSegments.at(random));
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
		_segments.at(0) = _segments.at(1);
		_segments.at(1) = _segments.at(2);
		int random = _rnd() % _loadedSegments.size();
		_segments.at(2) = _loadedSegments.at(random);
	} 
}

void Level::render(SDL_Renderer* renderer)
{
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
