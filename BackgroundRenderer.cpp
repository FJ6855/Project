#include "BackgroundRenderer.h"
#include <iostream>
BackgroundRenderer::~BackgroundRenderer()
{
}

void BackgroundRenderer::loadContent()
{
  _backgroundStatic = _rm->loadTexture("backgroundStatic");
  _backgroundMoving1 = _rm->loadTexture("backgroundMoving1");
  _backgroundMoving2 = _rm->loadTexture("backgroundMoving2");
  _pauseInscructionText = _rm->loadTexture("Press \"P\" to pause", SDL_Color{ 255, 255, 255 });
}

void BackgroundRenderer::render(Background* background, SDL_Renderer* renderer)
{
  _backgroundStatic->render(renderer, 0, 0, 896, 512);
  _pauseInscructionText->render(renderer, 896 - _pauseInscructionText->getWidth() - 5, 10, _pauseInscructionText->getWidth(), _pauseInscructionText->getHeight());
  //Går kanske att fixa på ngt annat sätt.. Onödigt att rita ut 3 st stora bilder...
  
  _backgroundMoving1->render(renderer, background->getX1() - 896, 162, 896, 350);
  _backgroundMoving1->render(renderer, background->getX1(), 162, 896 , 350);
  _backgroundMoving1->render(renderer, background->getX1() + 896, 162, 896, 350);

  _backgroundMoving2->render(renderer, background->getX2() - 896, 312, 896, 200);
  _backgroundMoving2->render(renderer, background->getX2(), 312, 896 , 200);
  _backgroundMoving2->render(renderer, background->getX2() + 896, 312, 896, 200);
}
