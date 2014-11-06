#include "Level.h";
#include "LevelSegment.h";

void Level::loadLevel()
{
	loadSegments();

	//TODO: call playerRenderer->loadContent()
}

void Level::handleInput()
{
	//TODO: call player->handleInput()
}

void Level::updateLogic()
{
	//TODO: call player->updateLogic(), handleCollisions()
}

void Level::render()
{
	//TODO: call all segements->render(), playerRenderer->render()
}

void Level::handleCollisions()
{
	//TODO: check collisions against segments and player
}

void Level::loadSegments()
{
	//TODO: load all segments into loadedSegments
	for (int i{0}; i < 10; ++i)
	{
		LevelSegment* ls = new LevelSegment(_rm);

		ls->loadLevelSegment("levelSegment" + std::to_string(i) + ".txt");

		_loadedSegments.pushBack(ls);;
	}
}
