#include "Level.h"
#include "LevelSegment.h"

void Level::handleInput()
{
	//TODO: call player->handleInput()
}

void Level::updateLogic()
{
	//TODO: call player->updateLogic(), handleCollisions()
}

void Level::render(SDL_Renderer* renderer)
{
  for (LevelSegment* ls : _segments)
    ls->render(renderer);
	//TODO: playerRenderer->render()
}

void Level::handleCollisions()
{
	//TODO: check collisions against segments and player
}

void Level::loadLevel()
{
	loadSegments();

	//TODO: call playerRenderer->loadContent()
}

void Level::loadSegments()
{
  //TODO: load all segments into loadedSegments
  //for (int i{0}; i < 3; ++i)
    //{
      LevelSegment* ls = new LevelSegment(_rm);
      ls->loadLevelSegment("levelSegment" + std::to_string(0));
      _loadedSegments.push_back(ls);
      //}
  
  // Add the first three loaded segments
  _segments.push_back(_loadedSegments.at(0));
}
