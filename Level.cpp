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
    for (int i{0}; i <= _maxDifficulty * 5; ++i)
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

    if (_player->getX() > 896)
    {
	_player->setX(_player->getX() - 896);
	_player->setMovementDifference(_player->getMovementDifference());
		
	delete _segments.at(0); //Free the memory
		
	_segments.at(0) = _segments.at(1);
	_segments.at(1) = _segments.at(2);
	       
	_segments.at(2) = new LevelSegment(*(_loadedSegments.at(Level::getRandom())));
    } 	

    // cap difficulty at maximum difficulty rating
    if (_player->getScore() < 110000)
    {
	if (_player->getScore() > _nextLevelCap)
	{
	    _nextLevelCap += 5000 * (_currentDifficulty / 3 + 1);

	    _currentDifficulty++;
	    
	    _player->setDifficulty(_currentDifficulty);
	}
    }

    //Logic for background
    if (_background->getX1() <= -896)
	_background->setX1(0);

    if (_background->getX2() <= -896)
	_background->setX2(0);

    if(_player->getMovementDifference() > 0 && _player->getX() > -896) 
	_background->setX1(_background->getX1() - _player->getSpeed() / 6);
    else if(_player->getMovementDifference() < 0 && _player->getX() > -896)
	_background->setX1(_background->getX1() + _player->getSpeed() / 6);

    if(_player->getMovementDifference() > 0 && _player->getX() > -896) 
	_background->setX2(_background->getX2() - _player->getSpeed() / 6 - 1);
    else if(_player->getMovementDifference() < 0 && _player->getX() > -896)
	_background->setX2(_background->getX2() + _player->getSpeed() / 6 + 1);

    handleCollision();

    _player->updatePowerUps();
}

void Level::render(SDL_Renderer* renderer)
{
    _backgroundRenderer->render(_background, renderer);

    if (_player->getX() > -896)
    {
	for (int i{}; i < 3; ++i)
	{
	    _segments.at(i)->setX(-896 + 896 * i - _player->getX());
	    _segments.at(i)->render(renderer);
	}
    }
    else
    {
	for (int i{}; i < 3; ++i)
	{
	    _segments.at(i)->setX(-896 + 896 * i + 896);
	    _segments.at(i)->render(renderer);
	}
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

void Level::reset()
{
    _player->reset();
    _currentDifficulty = 1;
    _nextLevelCap = 5000;

    _background->setX1(0);
    _background->setX2(0);

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
    // level segment from the 3 previous difficulties
    if (_currentDifficulty > 3)
    {
	int randomEasier = _rnd() % 10;
	int randomEasier2 = _rnd() % 8;
	int randomEasier3 = _rnd() % 5;
	
	if (randomEasier == 5)	    
	    random = random - 5 * 3;
	else if (randomEasier2 == 4)	    
	    random = random - 5 * 2;
	else if (randomEasier3 == 3)	    
	    random = random - 5 * 1;
    }

    return random;
}
