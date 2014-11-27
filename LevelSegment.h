#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "Object.h"
#include "BlinkingBlock.h"
#include "MovingBlock.h"
#include "SpeedBlock.h"
#include "Obstacle.h"
#include "Item.h"
#include "BlockRenderer.h"
#include "ObstacleRenderer.h"
#include "ItemRenderer.h"
#include "Player.h"

#ifndef LEVEL_SEGMENT_H
#define LEVEL_SEGMENT_H

class LevelSegment
{
  public:
	LevelSegment(ResourceManager* rm) : _rm{rm} 
	{
	  _blockRenderer = new BlockRenderer(rm);
	  _itemRenderer = new ItemRenderer(rm);
	  _obstacleRenderer = new ObstacleRenderer(rm);

	  _difficultyRating = 1;

	  _x = 0;
	  _y = 0;
	}

	LevelSegment(const LevelSegment& ls)
	{
		_rm = ls._rm;
		_difficultyRating = ls._difficultyRating;
		_x = ls._x;
		_y = ls._y;

		for (Block* b : ls._blocks)
		  {
		    MovingBlock* movingBlock = dynamic_cast<MovingBlock*>(b);
		    SpeedBlock* speedBlock = dynamic_cast<SpeedBlock*>(b);
		    BlinkingBlock* blinkingBlock = dynamic_cast<BlinkingBlock*>(b);
		    

		    if (movingBlock != nullptr)
		      _blocks.push_back(new MovingBlock(*(movingBlock)));
		    else if (speedBlock != nullptr)
		      _blocks.push_back(new SpeedBlock(*(speedBlock)));
		    else if (blinkingBlock != nullptr)
		      _blocks.push_back(new BlinkingBlock(*(blinkingBlock)));
		    else
		      _blocks.push_back(new Block(*(b)));
		  }

		for (Obstacle* o : ls._obstacles)
		  {
		      _obstacles.push_back(new Obstacle(*(o)));
		  }

		for (Item* i : ls._items)
		  {
		      _items.push_back(new Item(*(i)));
		  }

		_blockRenderer = ls._blockRenderer;
		_obstacleRenderer = ls._obstacleRenderer;
		_itemRenderer = ls._itemRenderer;
	}

	~LevelSegment();

	void loadLevelSegment(const std::string& fileName);
	void handleCollision(Player* player, int segmentIndex);
	void updateLogic();

	void render(SDL_Renderer* renderer);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	int getDifficultyRating();

  private:
	int _difficultyRating;
	int _x;
	int _y;
	int _updates;
	int _time;

	std::vector<Block*> _blocks;
	std::vector<Item*> _items;
	std::vector<Obstacle*> _obstacles;

	BlockRenderer* _blockRenderer;
	ItemRenderer* _itemRenderer;
	ObstacleRenderer* _obstacleRenderer;

	ResourceManager* _rm;

	template <typename T>
	void handleCollisionAgainstObjects(Player* player, std::vector<T*>& objects, int segmentIndex);
};

#endif
