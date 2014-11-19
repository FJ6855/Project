#include <fstream>
#include <sstream>

#include "LevelSegment.h"
#include "Block.h"

#include <iostream>

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
	  _blockRenderer->render(b, _x, renderer);
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

void LevelSegment::handleCollision(Player* player, int segmentIndex)
{
	int blockX;
	int blockY;

	float preX = player->getX() - player->getXvel();
	float preY = player->getY() - player->getYvel();

	int offset = -896 + 896 * segmentIndex - 448 + 16;
	for (Block* block : _blocks)
	{
		blockX = block->getX() * block->getWidth() + offset;
		blockY = block->getY() * block->getWidth();
		

		if (player->getYvel() > 0) //Player falling down
		{
			//Check if players bottom corners are inside a box
			if (player->getY() + player->getHeight() - 1 >= blockY && player->getY() + player->getHeight() - 1 <= blockY + block->getHeight() - 1)
			{
				if ((preX + player->getWidth() - 1 >= blockX && preX + player->getWidth() - 1 <= blockX + block->getWidth() - 1) || (preX >= blockX && preX <= blockX + block->getWidth() - 1))
				{
					player->setYvel(0);
					player->setY(blockY - player->getHeight());
				}
			}
		}
		else if (player->getYvel() < 0) //Player jumping up
		{
			//Check if players top corners are inside a box
			if (player->getY() >= blockY && player->getY() <= blockY + block->getHeight() - 1)
			{
				if ((preX + player->getWidth() - 1 >= blockX && preX + player->getWidth() - 1 <= blockX + block->getWidth() - 1) || (preX >= blockX && preX <= blockX + block->getWidth() - 1))
				{
					player->setYvel(0);
					player->setY(blockY + block->getHeight());
				}
			}
		}

		if (player->getXvel() > 0) //Player running right
		{
			//Check if players right corners are inside a box
			if (player->getX() + player->getWidth() - 1 >= blockX && player->getX() + player->getWidth() - 1 <= blockX + block->getWidth() - 1)
			{
				if ((preY + player->getHeight() - 1 >= blockY && preY + player->getHeight() - 1 <= blockY + block->getHeight() - 1) || (preY >= blockY && preY <= blockY + block->getHeight() -2))
				{
					player->setXvel(0);
					player->setX(blockX - player->getWidth());
				}
			}
		}
		else if (player->getXvel() < 0) //Player running left
		{
			//Check if players left corners are inside a box
			if (player->getX() >= blockX && player->getX() <= blockX + block->getWidth() - 1)
			{
				if ((preY + player->getHeight() - 1 >= blockY && preY + player->getHeight() - 1 <= blockY + block->getHeight() - 1) || (preY >= blockY && preY <= blockY + block->getHeight() - 2))
				{
					player->setXvel(0);
					player->setX(blockX + block->getWidth());
				}
			}
		}
	}
}

void LevelSegment::setX(int x)
{
	_x = x;
}

void LevelSegment::setY(int y)
{
	_y = y;
}

int LevelSegment::getX()
{
	return _x;
}

int LevelSegment::getY()
{
	return _y;
}
