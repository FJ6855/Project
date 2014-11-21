#include <SDL2/SDL.h>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
	Texture(int width, int height, SDL_Texture* texture) : _width{ width }, _height{ height }, _texture{ texture } {}
	~Texture();

	int getWidth();
	int getHeight();
	SDL_Texture* getTexture();
	void render(SDL_Renderer* renderer, int x, int y, int width, int height);
private:
	int _width;
	int _height;
	SDL_Texture* _texture;
};

#endif
