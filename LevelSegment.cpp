#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "LevelSegment.h"
#include "BlinkingBlock.h"
#include "SpeedBlock.h"

LevelSegment::~LevelSegment()
{

}

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
		  Block* b = new Block(x, y, 32, 32, BlockType::BlockType1);

		  _blocks.push_back(b);
		}
	      else if (c == 'B')
		{
		  Block* b = new BlinkingBlock(x, y, 32, 32, BlockType::BlinkingBlock1, 100);

		  _blocks.push_back(b);
		}
	      else if (c == 'S')
		{
		  Block* sb = new SpeedBlock(x, y, 32, 32, BlockType::SpeedBlock1, 3);

		  _blocks.push_back(sb);
		}
	      else if (c == 'Y')
		{
		  Obstacle* o = new Obstacle(x, y, 32, 32, ObstacleType::ObstacleType1, 10);

		  _obstacles.push_back(o);
		}
	      else if (c == 'Z')
		{
		  Item* i = new Item(x, y, 32, 32, ItemType::ItemType1, 10);

		  _items.push_back(i);
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
  for (Block* b : _blocks)
    {
      b->updateLogic();
    }
  /*
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
  
  for (Obstacle* o : _obstacles)
    {
      _obstacleRenderer->render(o, _x, renderer);
    }
  
  for (Item* i : _items)
    {
      _itemRenderer->render(i, _x, renderer);
    }
}

void LevelSegment::handleCollision(Player* player, int segmentIndex)
{
	handleCollisionAgainstObjects(player, _blocks, segmentIndex);
	handleCollisionAgainstObjects(player, _obstacles, segmentIndex);
	handleCollisionAgainstObjects(player, _items, segmentIndex);
}

template <typename T>
void LevelSegment::handleCollisionAgainstObjects(Player* player, std::vector<T*>& objects, int segmentIndex)
{
  int preX = player->getX() - player->getXvel();
  int preY = player->getY() - player->getYvel();

  int playerY;
  int playerX;

  if(player->getYvel() >= 0 && player->getYvel() < 1)
    {
      playerY = player->getY() + 1;
    }
  else 
    {
      playerY = player->getY();
    }

  if (player->getXvel() >= 0 && player->getXvel() < 1)
  {
	  playerX = player->getX() + 1;
  }
  else if (player->getXvel() <= 0 && player->getXvel() > -1)
  {
	  playerX = player->getX() - 1;
  }
  else
	  playerX = player->getX();

  int offset = -896 + 896 * segmentIndex - 448 + 16;

  int objectX;
  int objectY;

  for (int i{}; i < objects.size(); ++i)
  {
	  objectX = objects.at(i)->getX() * objects.at(i)->getWidth() + offset;
	  objectY = objects.at(i)->getY() * objects.at(i)->getWidth();

	  Block* block = dynamic_cast<Block*>(objects.at(i));
	  BlinkingBlock* blinkingBlock = dynamic_cast<BlinkingBlock*>(objects.at(i));
	  Obstacle* obstacle = dynamic_cast<Obstacle*>(objects.at(i));
	  Item* item = dynamic_cast<Item*>(objects.at(i));

	  if (blinkingBlock != nullptr && !blinkingBlock->isVisible())
	    {
	      continue;
	    }

	  if (player->getYvel() >= 0) //Player falling down
	  {
		  //Check if players bottom corners are inside a box
		  if (playerY + player->getHeight() - 1 >= objectY && playerY + player->getHeight() - 1 <= objectY + objects.at(i)->getHeight() - 1)
		  {
			  if ((preX + player->getWidth() - 1 >= objectX && preX + player->getWidth() - 1 <= objectX + objects.at(i)->getWidth() - 1) || (preX >= objectX && preX <= objectX + objects.at(i)->getWidth() - 1))
			  {
				  if (block != nullptr)
				  {
					  player->setState(PlayerState::running);
					  player->setYvel(0);
					  player->setY(objectY - player->getHeight());
					  					  
					  SpeedBlock* speedBlock = dynamic_cast<SpeedBlock*>(objects.at(i));
					  
					  if (speedBlock != nullptr)
					    player->setSpeed(speedBlock->getSpeedFactor());
					  else
					    player->resetSpeed();

					  continue;
				  }
				  else if (obstacle != nullptr)
				  {
					  player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
					  objects.erase(objects.begin() + i);
					  continue;
				  }
				  else if (item != nullptr)
				  {
					  player->setHealth(player->getHealth() + item->getHealth()); //Give player hp is the item was hpBox
					  objects.erase(objects.begin() + i);
					  continue;
				  }
			  }
		  }
	  }
	  else if (player->getYvel() < 0) //Player jumping up
	  {
	    
	    player->resetSpeed();

		  //Check if players top corners are inside a box
		  if (player->getY() >= objectY && player->getY() <= objectY + objects.at(i)->getHeight() - 1)
		  {
			  if ((preX + player->getWidth() - 1 >= objectX && preX + player->getWidth() - 1 <= objectX + objects.at(i)->getWidth() - 1) || (preX >= objectX && preX <= objectX + objects.at(i)->getWidth() - 1))
			  {
				  if (block != nullptr)
				  {
					  player->setYvel(0);
					  player->setY(objectY + block->getHeight());
					  continue;
				  }
				  else if (obstacle != nullptr)
				  {
					  player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
					  objects.erase(objects.begin() + i);
					  continue;
				  }
				  else if (item != nullptr)
				  {
					  player->setHealth(player->getHealth() + item->getHealth()); //Give player hp is the item was hpBox
					  objects.erase(objects.begin() + i);
					  continue;
				  }
			  }
		  }
	  }

	  if (player->getXvel() > 0) //Player running right
	  {
		  //Check if players right corners are inside a box
		  if (playerX + player->getWidth() - 1 >= objectX && playerX + player->getWidth() - 1 <= objectX + objects.at(i)->getWidth() - 1)
		  {
			  if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + objects.at(i)->getHeight() - 1) || (preY >= objectY && preY <= objectY + objects.at(i)->getHeight() - 2))
			  {
				  if (block != nullptr)
				  {
					  player->setXvel(0);
					  player->setX(objectX - player->getWidth());
					  continue;
				  }
				  else if (obstacle != nullptr)
				  {
					  player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
					  objects.erase(objects.begin() + i);
					  continue;
				  }
				  else if (item != nullptr)
				  {
					  player->setHealth(player->getHealth() + item->getHealth()); //Give player hp is the item was hpBox
					  objects.erase(objects.begin() + i);
					  continue;
				  }
			  }
		  }
	  }
	  else if (player->getXvel() < 0) //Player running left
	  {
		  //Check if players left corners are inside a box
		  if (playerX >= objectX && playerX <= objectX + objects.at(i)->getWidth() - 1)
		  {
			  if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + objects.at(i)->getHeight() - 1) || (preY >= objectY && preY <= objectY + objects.at(i)->getHeight() - 2))
			  {
				  if (block != nullptr)
				  {
					  player->setXvel(0);
					  player->setX(objectX + block->getWidth());
					  continue;
				  }
				  else if (obstacle != nullptr)
				  {
					  player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
					  objects.erase(objects.begin() + i);
					  continue;
				  }
				  else if (item != nullptr)
				  {
					  player->setHealth(player->getHealth() + item->getHealth()); //Give player hp is the item was hpBox
					  objects.erase(objects.begin() + i);
					  continue;
				  }
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
