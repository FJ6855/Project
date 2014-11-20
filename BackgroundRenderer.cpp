#include "BackgroundRenderer.h"

BackgroundRenderer::~BackgroundRenderer()
{
}

void BackgroundRenderer::loadContent()
{
	_backgroundStatic = _rm->loadTexture("backgroundStatic");
	_backgroundMoving = _rm->loadTexture("backgroundMoving");
}

void BackgroundRenderer::render(Background* background, SDL_Renderer* renderer)
{
	_backgroundStatic->render(renderer, 0, 0, 896, 300);

	//Går kanske att fixa på ngt annat sätt.. Onödigt att rita ut 3 st stora bilder...
	_backgroundMoving->render(renderer, background->getX() - 896, 200, 896, 312);
	_backgroundMoving->render(renderer, background->getX(), 200, 896 , 312);
	_backgroundMoving->render(renderer, background->getX() + 896, 200, 896, 312);
}