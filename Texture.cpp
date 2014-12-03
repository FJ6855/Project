#include "Texture.h"

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

int Texture::getWidth()
{
    return _width;
}

int Texture::getHeight()
{
    return _height;
}

SDL_Texture* Texture::getTexture()
{
    return _texture;
}

void Texture::render(SDL_Renderer* renderer, int x, int y, int width, int height)
{
    if (_texture != nullptr)
    {
	SDL_Rect renderRect = { x, y, width, height };
	SDL_RenderCopy(renderer, _texture, NULL, &renderRect);
    }
}
