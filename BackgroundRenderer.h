#include "Renderer.h"
#include "Background.h"

#ifndef BACKGROUNDRENDERER_H
#define BACKGROUNDRENDERER_H

class BackgroundRenderer : public Renderer
{
public:
    BackgroundRenderer(ResourceManager* rm) : Renderer(rm) 
    {
	loadContent();
    }

    ~BackgroundRenderer()
    {
	delete _backgroundStatic;
	delete _backgroundMoving1;
	delete _backgroundMoving2;
	delete _pauseInscructionText;
    }

    void loadContent() override;
    void render(Background* background, SDL_Renderer* renderer);

private:
    Texture* _backgroundStatic;
    Texture* _backgroundMoving1;
    Texture* _backgroundMoving2;
    Texture* _pauseInscructionText;
};

#endif
