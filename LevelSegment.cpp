#include <fstream>
#include <sstream>

#include "LevelSegment.h"
#include "Block.h"

void LevelSegment::loadLevelSegment(const std::string& fileName)
{
  std::ifstream file("./res/LevelSegments/" + fileName + ".txt");

	if (file.is_open())
	{
		int x = 0;
		int y = 0;

		std::string line;

		while (getline(file, line))
		{
			std::stringstream ss(line);
			char c;

			while (ss >> c)
			{
				if (c == 'X')
				{
					Block* b = new Block(x, y, 32, 32, type1);

					_blocks.push_back(b);
				}
				else if (c == 'Y')
				{
					//Obstacle* o = new Obstacle(x, y, 32, 32);

					//_obstacles.push_back(o);
				}
				else if (c == 'Z')
				{
					//Item* i = new Item(x, y, 32, 32);

					//_items.push_back(i);
				}

				++x;
			}

			x = 0;
			++y;
		}
	}
	else
	{
	  std::cout << "Could not open file: LevelSegments/" + fileName << std::endl;
	}
}

void LevelSegment::updateLogic()
{
  /*for (Block* b : _blocks)
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
		}*/
}

void LevelSegment::render(SDL_Renderer* renderer)
{
  for (Block* b : _blocks)
	{
	  _blockRenderer->render(b, renderer);
	}
  /*
	for (Obstacle* o : _obstacles)
	{
		_obstacleRenderer->render(o);
	}

	for (Items* b : _blocks)
	{
		_itemRenderer->render(i);
		}*/
}

/*void LevelSegment::handleCollisions(Player* player)
{
	//TODO: check collision against blocks, obstacles and items
}*/
