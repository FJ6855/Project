#include "Renderer.h"
#include "ResourceManager.h"
#include "Obstacle.h"

#ifndef OBSTACLE_RENDERER_H
#define OBSTACLE_RENDERER_H

class ObstacleRenderer : public Renderer
{
public:
    ObstacleRenderer(ResourceManager* rm) : Renderer{ rm }
    {
	loadContent();
    }

    ~ObstacleRenderer() = default;

    void loadContent() override;
    void render(Obstacle* obstacle, int offset, SDL_Renderer* renderer);
};

#endif

