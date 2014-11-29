#include "BackgroundRenderer.h"

BackgroundRenderer::~BackgroundRenderer()
{
}

void BackgroundRenderer::loadContent()
{
	_backgroundStatic = _rm->loadTexture("backgroundStatic");
	_backgroundMoving = _rm->loadTexture("backgroundMoving");
	_pauseInscructionText = _rm->loadTexture("Press \"P\" to pause", SDL_Color{ 255, 255, 255 });
}

void BackgroundRenderer::render(Background* background, SDL_Renderer* renderer)
{
	_backgroundStatic->render(renderer, 0, 0, 896, 512);
	_pauseInscructionText->render(renderer, 896 - _pauseInscructionText->getWidth() - 5, 10, _pauseInscructionText->getWidth(), _pauseInscructionText->getHeight());
	//Går kanske att fixa på ngt annat sätt.. Onödigt att rita ut 3 st stora bilder...
	_backgroundMoving->render(renderer, background->getX() - 896, 312, 896, 200);
	_backgroundMoving->render(renderer, background->getX(), 312, 896 , 200);
	_backgroundMoving->render(renderer, background->getX() + 896, 312, 896, 200);
}