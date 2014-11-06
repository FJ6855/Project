#include <vector>

#include "ResourceManager.h"

class LevelSegment
{
  public:
	LevelSegment(ResourceManager rm) : _rm{rm} 
	{
		_blockRenderer = new BlockRenderer(rm);
		_obstacleRenderer = new ObstacleRenderer(rm);
		_itemRenderer = new ItemRenderer(rm);

		_x = 0;
		_y = 0;

		_width = 16;
		_height = 5;		
	}

	void loadLevelSegment(const string& fileName);

	void updateLogic();

	void render();

  private:
	ResourceManager* _rm;
	
	int _x;
	int _y;
	
	int _width;
	int _height;
	
	int _difficultyRating;

	vector<Object*> _blocks;
	vector<Object*> _obstacles;
	vector<Object*> _items;

	BlockRenderer* _blockRenderer;
	ObstacleRenderer* _obstacleRenderer;
	ItemRenderer* _itemRenderer;

	void handleCollision(Player* player);
};
