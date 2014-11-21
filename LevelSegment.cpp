#include <fstream>
#include <sstream>
#include <algorithm>

#include "LevelSegment.h"

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
		  Block* b = new Block(x, y, 32, 32, BlockType::BlockType1);

		  _blocks.push_back(b);
		}
	      else if (c == 'Y')
		{
		  //Obstacle* o = new Obstacle(x, y, 32, 32);

		  //_obstacles.push_back(o);
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
  */

  for (Item* i : _items)
    {
      _itemRenderer->render(i, _x, renderer);
    }
}

void LevelSegment::handleCollision(Player* player, int segmentIndex)
{
  handleCollisionAgainstObjects(player, _blocks, segmentIndex);
  handleCollisionAgainstObjects(player, _items, segmentIndex);
	/*for (Block* block : _blocks)
	{
		blockX = block->getX() * block->getWidth() + offset;
		blockY = block->getY() * block->getWidth();
		

		if (player->getYvel() >= 0) //Player falling down
		  {		   
		    //Check if players bottom corners are inside a box
		    if (playerY + player->getHeight() - 1 >= blockY && playerY + player->getHeight() - 1 <= blockY + block->getHeight() - 1)
		      {
			if ((preX + player->getWidth() - 1 >= blockX && preX + player->getWidth() - 1 <= blockX + block->getWidth() - 1) || (preX >= blockX && preX <= blockX + block->getWidth() - 1))
			  {
			    player->setState(PlayerState::running);
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
		}*/
}

template <typename T>
void LevelSegment::handleCollisionAgainstObjects(Player* player, std::vector<T*>& objects, int segmentIndex)
{
  int preX = player->getX() - player->getXvel();
  int preY = player->getY() - player->getYvel();

  int playerY;

  if(player->getYvel() >= 0 && player->getYvel() < 1)
    {
      playerY = player->getY() + 1;
    }
  else 
    {
      playerY = player->getY();
    }

  int offset = -896 + 896 * segmentIndex - 448 + 16;

  int objectX;
  int objectY;
	
  int objectCounter = 0;

  for (T* object : objects)
    {
      objectX = object->getX() * object->getWidth() + offset;
      objectY = object->getY() * object->getWidth();

      if (player->getYvel() >= 0) //Player falling down
	{		   
	  //Check if players bottom corners are inside a box
	  if (playerY + player->getHeight() - 1 >= objectY && playerY + player->getHeight() - 1 <= objectY + object->getHeight() - 1)
	    {
	      if ((preX + player->getWidth() - 1 >= objectX && preX + player->getWidth() - 1 <= objectX + object->getWidth() - 1) || (preX >= objectX && preX <= objectX + object->getWidth() - 1))
		{
		  if (dynamic_cast<Block*>(object))
		    {
		      player->setState(PlayerState::running);
		      player->setYvel(0);
		      player->setY(objectY - player->getHeight());
			  
		    }
		  else if (dynamic_cast<Item*>(object))
		    {
		      objects.erase(objects.begin() + objectCounter);
		    }
		}
	    }
	}
      else if (player->getYvel() < 0) //Player jumping up
	{
	  //Check if players top corners are inside a box
	  if (player->getY() >= objectY && player->getY() <= objectY + object->getHeight() - 1)
	    {
	      if ((preX + player->getWidth() - 1 >= objectX && preX + player->getWidth() - 1 <= objectX + object->getWidth() - 1) || (preX >= objectX && preX <= objectX + object->getWidth() - 1))
		{
		   if (dynamic_cast<Block*>(object))
		    {
		      player->setYvel(0);
		      player->setY(objectY + object->getHeight());
		    }
		   else if (dynamic_cast<Item*>(object))
		    {		      
		      objects.erase(objects.begin() + objectCounter);
		    }
		}
	    }
	}

      if (player->getXvel() > 0) //Player running right
	{
	  //Check if players right corners are inside a box
	  if (player->getX() + player->getWidth() - 1 >= objectX && player->getX() + player->getWidth() - 1 <= objectX + object->getWidth() - 1)
	    {
	      if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + object->getHeight() - 1) || (preY >= objectY && preY <= objectY + object->getHeight() -2))
		{
		  if (dynamic_cast<Block*>(object))
		    {
		      player->setXvel(0);
		      player->setX(objectX - player->getWidth());
		    }
		   else if (dynamic_cast<Item*>(object))
		    {
		      objects.erase(objects.begin() + objectCounter);		      
		    }
		}
	    }
	}
      else if (player->getXvel() < 0) //Player running left
	{
	  //Check if players left corners are inside a box
	  if (player->getX() >= objectX && player->getX() <= objectX + object->getWidth() - 1)
	    {
	      if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + object->getHeight() - 1) || (preY >= objectY && preY <= objectY + object->getHeight() - 2))
		{
		  if (dynamic_cast<Block*>(object))
		    {		      
		      player->setXvel(0);
		      player->setX(objectX + object->getWidth());
		    }
		   else if (dynamic_cast<Item*>(object))
		    {
		      objects.erase(objects.begin() + objectCounter);		      
		    }
		}
	    }
	}

      ++objectCounter;
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
