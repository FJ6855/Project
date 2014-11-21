#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "Object.h"
#include "BlockRenderer.h"
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
	  _difficultyRating = 1;
	  //_obstacleRenderer = new ObstacleRenderer(rm);
	  _itemRenderer = new ItemRenderer(rm);

	  _x = 0;
	  _y = 0;
	}

	LevelSegment(const LevelSegment& ls)
	  {
	    _rm = ls._rm;
	    _difficultyRating = ls._difficultyRating;
	    _x = ls._x;
	    _y = ls._y;
	    _blocks = ls._blocks;
	    _items = ls._items;
	    _blockRenderer = ls._blockRenderer;
	    _itemRenderer = ls._itemRenderer;
	  }

	void loadLevelSegment(const std::string& fileName);
	void handleCollision(Player* player, int segmentIndex);
	void updateLogic();

	void render(SDL_Renderer* renderer);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

  private:
	ResourceManager* _rm;
	
	int _difficultyRating;

	int _x;
	int _y;

	std::vector<Block*> _blocks;
	//vector<Object*> _obstacles;
	std::vector<Item*> _items;

	BlockRenderer* _blockRenderer;
	//ObstacleRenderer* _obstacleRenderer;
	ItemRenderer* _itemRenderer;

	template <typename T>
	void handleCollisionAgainstObjects(Player* player, std::vector<T*>& objects, int segmentIndex);
};

#endif
