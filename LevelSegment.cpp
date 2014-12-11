#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cctype>

#include "LevelSegment.h"

void LevelSegment::loadLevelSegment(const std::string& fileName)
{
    std::ifstream file("./res/LevelSegments/" + fileName + ".txt");
    
    if (file.is_open())
    {
	int x = 0;
	int y = -1;
	
	std::string line;
	
	while (getline(file, line))
	{
	    std::stringstream ss(line);
	    char c;
	    
	    if (y == -1)
		ss >> _difficultyRating;
	    
	    while (ss >> c)
	    {
		if (c == 'X')
		{
		    Block* b = new Block(x, y, 32, 32, static_cast<BlockType>(_difficultyRating));
		    
		    _blocks.push_back(b);
		}
		else if (c == 'B')
		{
		    Block* b = new BlinkingBlock(x, y, 32, 32, 100);

		    _blocks.push_back(b);
		}
		else if (c == 'S')
		{
		    Block* sb = new SpeedBlock(x, y, 32, 32, BlockType::SpeedBlockRight1, 2);

		    _blocks.push_back(sb);
		}
		else if (c == 'D')
		{
		    Block* sb = new SpeedBlock(x, y, 32, 32, BlockType::SpeedBlockLeft1, -2);

		    _blocks.push_back(sb);
		}
		else if (c == 'M')
		{
		    int interval;
		    Block* mb;

		    if (isdigit(ss.peek()))
		    {
			ss >> interval;

			mb = new MovingBlock(x, y, 32, 32, 2.0f, interval);
		    }
		    else
		    {
			mb = new MovingBlock(x, y, 32, 32, 2.0f, 5);
		    }
		    
		    _blocks.push_back(mb);
		}
		else if (c == 'Y')
		{
		    Obstacle* o = new Obstacle(x, y, 32, 32, 10);

		    _obstacles.push_back(o);
		}
		else if (c == 'H')
		{
		    Item* h = new Health(x, y, 32, 32, 10);

		    _items.push_back(h);
		}
		else if (c == 'P')
		{		    
		    int random = _rnd() % 3 + 1;
		    Item* p;
		    
		    if (random == 1)
			p = new SpeedBoost(x, y, 32, 32, 10000, 12);
		    else if (random == 2)
			p = new DoubleJump(x, y, 32, 32, 10000);
		    else if (random == 3)
			p = new GlideJump(x, y, 32, 32, 10000);
		    
		    _items.push_back(p);
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
    {
	playerX = player->getX();
    }

    int offset = -896 + 896 * segmentIndex - 448 + 16;

    int objectX;
    int objectY;
  
    // Checking if player has been moved by a moving block, 
    // should only happen once per collision handling
    bool hasBeenMoved = false;

    for (int i{}; i < objects.size(); ++i)
    {
	Object* object = dynamic_cast<Object*>(objects.at(i));

	Block* block = dynamic_cast<Block*>(object);
	MovingBlock* movingBlock = dynamic_cast<MovingBlock*>(block);
	BlinkingBlock* blinkingBlock = dynamic_cast<BlinkingBlock*>(block);

	Obstacle* obstacle = dynamic_cast<Obstacle*>(object);
	Item* item = dynamic_cast<Item*>(object);
       
	if (blinkingBlock != nullptr && !blinkingBlock->isVisible())
	{
	    continue;
	}

	objectX = object->getX() * object->getWidth() + offset;
    
	if (movingBlock != nullptr)
	    objectX += movingBlock->getMovingX();
	
	objectY = object->getY() * object->getWidth();

	if (player->getYvel() >= 0) //Player falling down
	{
	    //Check if players bottom corners are inside a box
	    if (playerY + player->getHeight() - 1 >= objectY && playerY + player->getHeight() - 1 <= objectY + object->getHeight() - 1)
	    {
		if ((preX + player->getWidth() - 1 >= objectX && preX + player->getWidth() - 1 <= objectX + object->getWidth() - 1) || (preX >= objectX && preX <= objectX + object->getWidth() - 1))
		{
		    if (block != nullptr)
		    {
			if (player->getState() != PlayerState::dead)
			{
			    if (player->getXvel() == 0)
				player->setState(PlayerState::standing);
			    else
				player->setState(PlayerState::running);
			}

			player->setYvel(0);
			player->setY(objectY - player->getHeight());
					  					  
			SpeedBlock* speedBlock = dynamic_cast<SpeedBlock*>(block);
					  
			if (speedBlock != nullptr)
			{
			    player->setAirSpeed(speedBlock->getSpeedFactor());
			    player->setX(player->getX() + speedBlock->getSpeedFactor());
			}
			else if (movingBlock != nullptr && hasBeenMoved == false)
			{
			    player->setX(player->getX() + movingBlock->getSpeed());
			    hasBeenMoved = true;
			}
			else 
			{
			    player->setAirSpeed(0);
			}			

			continue;
		    }
		    else if (obstacle != nullptr)
		    {
			if (!player->isGod())
			    player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
			
			objects.erase(objects.begin() + i);
			
			continue;
		    }
		    else if (item != nullptr)
		    {
			Health* health = dynamic_cast<Health*>(item);
			PowerUp* powerUp = dynamic_cast<PowerUp*>(item);

			if (health != nullptr)
			{
			    player->setHealth(player->getHealth() + health->getHealth());
			}
			else if (powerUp != nullptr)
			{
			    player->addPowerUp(powerUp);
			}

			objects.erase(objects.begin() + i);
			
			continue;
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
		    if (block != nullptr)
		    {
			player->setYvel(0);
			player->setY(objectY + block->getHeight());
			continue;
		    }
		    else if (obstacle != nullptr)
		    {
			if (!player->isGod())
			    player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
			objects.erase(objects.begin() + i);
			continue;
		    }
		    else if (item != nullptr)
		    {
			Health* health = dynamic_cast<Health*>(item);
			PowerUp* powerUp = dynamic_cast<PowerUp*>(item);

			if (health != nullptr)
			{
			    player->setHealth(player->getHealth() + health->getHealth());
			}
			else if (powerUp != nullptr)
			{
			    player->addPowerUp(powerUp);
			}
			
			objects.erase(objects.begin() + i);
			
			continue;
		    }
		}
	    }
	}

	//Check if players right corners are inside a box
	if (playerX + player->getWidth() - 1 >= objectX && playerX + player->getWidth() - 1 <= objectX + object->getWidth() - 1)
	{
	    if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + object->getHeight() - 1) || (preY >= objectY && preY <= objectY + object->getHeight() - 2))
	    {
		if (block != nullptr)
		{
		    player->setXvel(0);
		    player->setX(objectX - player->getWidth());
		    continue;
		}
		else if (obstacle != nullptr)
		{
		    if (!player->isGod())
			player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
		    objects.erase(objects.begin() + i);
		    continue;
		}
		else if (item != nullptr)
		{
		    Health* health = dynamic_cast<Health*>(item);
		    PowerUp* powerUp = dynamic_cast<PowerUp*>(item);

		    if (health != nullptr)
		    {
			player->setHealth(player->getHealth() + health->getHealth());
		    }
		    else if (powerUp != nullptr)
		    {
			player->addPowerUp(powerUp);
		    }

		    objects.erase(objects.begin() + i);
			
		    continue;
		}
	    }
	}
	//Check if players left corners are inside a box
	if (playerX >= objectX && playerX <= objectX + object->getWidth() - 1)
	{
	    if ((preY + player->getHeight() - 1 >= objectY && preY + player->getHeight() - 1 <= objectY + object->getHeight() - 1) || (preY >= objectY && preY <= objectY + object->getHeight() - 2))
	    {
		if (block != nullptr)
		{
		    player->setXvel(0);
		    player->setX(objectX + block->getWidth());
		    continue;
		}
		else if (obstacle != nullptr)
		{
		    if (!player->isGod())
			player->setHealth(player->getHealth() - obstacle->getDamage()); // Reduce player hp with the obstacle damage
		    objects.erase(objects.begin() + i);
		    continue;
		}
		else if (item != nullptr)
		{
		    Health* health = dynamic_cast<Health*>(item);
		    PowerUp* powerUp = dynamic_cast<PowerUp*>(item);

		    if (health != nullptr)
		    {
			player->setHealth(player->getHealth() + health->getHealth());
		    }
		    else if (powerUp != nullptr)
		    {
			player->addPowerUp(powerUp);
		    }

		    objects.erase(objects.begin() + i);

		    continue;
		}
	    }
	}
    }
}

void LevelSegment::deleteRenderers()
{
    delete _blockRenderer;
    _blockRenderer = nullptr;

    delete _itemRenderer;
    _itemRenderer = nullptr;

    delete _obstacleRenderer;
    _obstacleRenderer = nullptr;
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

int LevelSegment::getDifficultyRating()
{
    return _difficultyRating;
}

std::vector<Block*> LevelSegment::getBlocks() 
{
    return _blocks;
}
