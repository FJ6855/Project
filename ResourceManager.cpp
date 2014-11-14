#include "ResourceManager.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

ResourceManager::~ResourceManager()
{

}

Texture* ResourceManager::loadTexture(int width, int height, int red, int green, int blue)
{
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = nullptr;

	//create image
	loadedSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	//fill the image with the color
	SDL_FillRect(loadedSurface, NULL, SDL_MapRGB(loadedSurface->format, red, green, blue));

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//make a texture from the image
	newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);

	if (newTexture == NULL)
	{
		printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
	}

	SDL_FreeSurface(loadedSurface);

	return new Texture(width, height, newTexture);
}

Texture* ResourceManager::loadTexture(std::string fileName)
{
	int width;
	int height;
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(("./res/textures/" + fileName + ".png").c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", ("./res/textures/" + fileName + ".png").c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", ("./res/textures/" + fileName + ".png").c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return new Texture(width, height, newTexture);
}

Texture* ResourceManager::loadTexture(std::string textureText, SDL_Color textColor)
{
	int width;
	int height;
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = TTF_RenderText_Solid(_font, textureText.c_str(), textColor);

	if (loadedSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(loadedSurface);
	}

	return new Texture(width, height, newTexture);
}