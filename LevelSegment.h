#include <vector>

class LevelSegment
{
  public:
	LevelSegment(ResourceManager rm) : _rm{rm} {}

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
