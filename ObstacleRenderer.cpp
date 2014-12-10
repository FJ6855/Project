#include "ObstacleRenderer.h"

void ObstacleRenderer::loadContent()
{
    _textures.push_back(_rm->loadTexture("obstacle"));
}

void ObstacleRenderer::render(Obstacle* obstacle, int offset, SDL_Renderer* renderer)
{
    _textures.at(0)->render(renderer, obstacle->getX() * obstacle->getWidth() + offset, obstacle->getY() * obstacle->getHeight(), obstacle->getWidth(), obstacle->getHeight());
}
