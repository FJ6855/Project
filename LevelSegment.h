#include <iostream>
#include <vector>
#include <random>

#include "ResourceManager.h"
#include "Object.h"
#include "BlinkingBlock.h"
#include "MovingBlock.h"
#include "SpeedBlock.h"
#include "Obstacle.h"
#include "Item.h"
#include "Health.h"
#include "PowerUp.h"
#include "SpeedBoost.h"
#include "DoubleJump.h"
#include "GlideJump.h"
#include "BlockRenderer.h"
#include "ObstacleRenderer.h"
#include "ItemRenderer.h"
#include "Player.h"

#ifndef LEVEL_SEGMENT_H
#define LEVEL_SEGMENT_H

class LevelSegment
{
public:
    LevelSegment(ResourceManager* rm, BlockRenderer* blockRenderer, ItemRenderer* itemRenderer, ObstacleRenderer* obstacleRenderer) : _rm{rm}, _blockRenderer{blockRenderer}, _itemRenderer{itemRenderer}, _obstacleRenderer{obstacleRenderer} 
    {
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
	    _blocks.push_back(b->clone());

	for (Obstacle* o : ls._obstacles)
	    _obstacles.push_back(o->clone());

	for (Item* i : ls._items)
	    _items.push_back(i->clone());

	_blockRenderer = ls._blockRenderer;
	_obstacleRenderer = ls._obstacleRenderer;
	_itemRenderer = ls._itemRenderer;
    }

    ~LevelSegment()
    {
	for (Block* b : _blocks)
	{
	    delete b;
	    b = nullptr;
	}

	for (Item* i : _items)
	{
	    delete i;
	    i = nullptr;
	}
	
	for (Obstacle* o : _obstacles)
	{
	    delete o;
	    o = nullptr;
	}
    }

    void loadLevelSegment(const std::string& fileName);
    void handleCollision(Player* player, int segmentIndex);
    void updateLogic();

    void render(SDL_Renderer* renderer);

    void deleteRenderers();

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    std::vector<Block*> getBlocks();

    int getDifficultyRating();

private:
    int _difficultyRating;
    int _x;
    int _y;
    int _updates;
    int _time;

    std::random_device _rnd;

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
