#include <iostream>
#include <vector>

#include "ResourceManager.h"
#include "Object.h"
#include "BlockRenderer.h"

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
	  //_itemRenderer = new ItemRenderer(rm);

	  _x = 0;
	  _y = 0;
	}

	void loadLevelSegment(const std::string& fileName);

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
	//vector<Object*> _items;

	BlockRenderer* _blockRenderer;
	//ObstacleRenderer* _obstacleRenderer;
	//ItemRenderer* _itemRenderer;

	//void handleCollision(Player* player);
};

#endif
