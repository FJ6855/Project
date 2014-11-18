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
	  //_obstacleRenderer = new ObstacleRenderer(rm);
	  //_itemRenderer = new ItemRenderer(rm);

		_x = 0;
		_y = 0;

		_width = 16;
		_height = 5;		
	}

	void loadLevelSegment(const std::string& fileName);

	void updateLogic();

	void render(SDL_Renderer* renderer);

  private:
	ResourceManager* _rm;
	
	int _x;
	int _y;
	
	int _width;
	int _height;
	
	int _difficultyRating;

	std::vector<Block*> _blocks;
	//vector<Object*> _obstacles;
	//vector<Object*> _items;

	BlockRenderer* _blockRenderer;
	//ObstacleRenderer* _obstacleRenderer;
	//ItemRenderer* _itemRenderer;

	//void handleCollision(Player* player);
};

#endif
