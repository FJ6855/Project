#include "Game.h"

#include <iostream>
#include <SDL2/SDL.h>
void Game::run()
{
  handleInput();

  updateLogic();

  render();
}

void Game::handleInput()
{
// TODO: check for game paused, call level->handleInput
  if(_input->getPressed(SDL_SCANCODE_P))
  {
    _paused = !_paused;
  }
  
  if(_input->getKey(SDL_SCANCODE_W))
    std::cout << "w �r nedtryckt" << std::endl;
  if(_input->getKey(SDL_SCANCODE_A))
    std::cout << "a �r nedtryckt" << std::endl;
  if(_input->getKey(SDL_SCANCODE_S))
    std::cout << "s �r nedtryckt" << std::endl;
  if(_input->getKey(SDL_SCANCODE_D))
    std::cout << "d �r nedtryckt" << std::endl;

  if(_input->getPressed(SDL_SCANCODE_SPACE))
    std::cout << "Du tryckte p� space" << std::endl;


}
void Game::updateLogic()
{
  // TODO: call level->updateLogic()
}

void Game::render()
{
  // TODO: call level->render()
}
