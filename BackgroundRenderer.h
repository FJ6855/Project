#include "Renderer.h"
#include "Background.h"

#ifndef BACKGROUNDRENDERER_H
#define BACKGROUNDRENDERER_H

class BackgroundRenderer : public Renderer
{
public:
	BackgroundRenderer(ResourceManager* rm) : Renderer{ rm }
	{
		loadContent();
	}
	~BackgroundRenderer();

	void loadContent() override;
	void render(Background* background, SDL_Renderer* renderer);

private:
	Texture* _backgroundStatic;
	Texture* _backgroundMoving;
};

#endif
