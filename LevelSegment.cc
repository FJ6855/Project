#include "LevelSegment.cc";
#include <fstream>

void LevelSegment::loadLevelSegment(const string& fileName)
{
	ifstream file(fileName);

	if (file.is_open())
	{
		char c;

		while (file >> c;)
		{
			if (c == 'X')
			{
				Block* b = new Block();

				_blocks.push_back(b);
			}

			//TODO: create items and obstacles
		}
	}
}

void LevelSegment::updateLogic()
{
	for (Block* b : _blocks)
	{
		b->updateLogic();
	}

	for (Obstacle* o : _obstacles)
	{
		o->updateLogic();
	}

	for (Item* i : _items)
	{
		i->updateLogic();
	}
}

void LevelSegment::render()
{
	for (Block* b : _blocks)
	{
		_blockRenderer->render(b);
	}

	for (Obstacle* o : _obstacles)
	{
		_obstacleRenderer->render(o);
	}

	for (Items* b : _blocks)
	{
		_itemRenderer->render(i);
	}
}

void LevelSegment::handleCollisions(Player* player)
{
	//TODO: check collision against blocks, obstacles and items
}
