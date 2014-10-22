#include "Game.h";

void Game::run()
{
  handleInput();

  updateLogic();

  render();
}

void Game::handleInput()
{
  // TODO: check for game paused, call level->handleInput
}

void Game::updateLogic()
{
  // TODO: call level->updateLogic()
}

void Game::render()
{
  // TODO: call level->render()
}
