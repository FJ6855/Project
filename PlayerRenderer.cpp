#include "PlayerRenderer.h"
#include <string>
#include <iostream>

PlayerRenderer::~PlayerRenderer()
{

}

void PlayerRenderer::loadContent()
{
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight0"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight1"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight2"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight3"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight4"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningRight5"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft0"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft1"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft2"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft3"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft4"));
    _textures.push_back(_rm->loadTexture("playerTextureRunningLeft5"));

    _playerTextureInAirRight = _rm->loadTexture("playerTextureJumpingRight");
    _playerTextureInAirLeft = _rm->loadTexture("playerTextureJumpingLeft");

    _healthBarTextTexture = _rm->loadTexture("Health: ", SDL_Color{ 255, 255, 255 });
    _healthBarTexture = _rm->loadTexture(1, 16, 255, 0, 0);

    _scoreTextTexture = _rm->loadTexture("Score: ", SDL_Color{ 255, 255, 255 });
    _lastHighestScoreTextTexture = _rm->loadTexture("Your highest score: ", SDL_Color{ 255, 255, 255 });

    _lastScoreTextTexture = _rm->loadTexture("Last rounds score: ", SDL_Color{ 255, 255, 255 });

    _speedBoostTimerTexture = _rm->loadTexture(1, 16, 255, 255, 0); 
    _doubleJumpTimerTexture = _rm->loadTexture(1, 16, 0, 255, 0);
    _glideJumpTimerTexture = _rm->loadTexture(1, 16, 0, 0, 255);  

    _speedBoostTimerTextTexture = _rm->loadTexture("Speed boost timer: ", SDL_Color{ 255, 255, 255 });
    _doubleJumpTimerTextTexture = _rm->loadTexture("Double jump timer: ", SDL_Color{ 255, 255, 255 });
    _glideJumpTimerTextTexture = _rm->loadTexture("Glide jump timer: ", SDL_Color{ 255, 255, 255 });
}

void PlayerRenderer::render(Player* player, SDL_Renderer* renderer)
{
    //Render player
    if (_playerFrame > 17) 
	_playerFrame = 0;

    if (player->getState() == PlayerState::inAir || player->getState() == PlayerState::jumping)
    {
	if (player->getDirection() == left)
	    _playerTexture = _playerTextureInAirLeft;
	else if (player->getDirection() == right)
	    _playerTexture = _playerTextureInAirRight;
    }
    else if (player->getState() == PlayerState::standing)
    {
	if (player->getDirection() == right)
	    _playerTexture = _textures.at(0);
	else if (player->getDirection() == left)
	    _playerTexture = _textures.at(0 + 6);
    }
    else if (player->getState() == PlayerState::running)
    {	
	if (player->getDirection() == right)
	{
	    _playerTexture = _textures.at(_playerFrame / 3);
	}
	else
	{
	    _playerTexture = _textures.at(_playerFrame / 3 + 6);
	}
	
	_playerFrame++;
    }  
    
    int playerPosX = 448 - (player->getWidth() / 2);

    if (player->getX() < -896)    
	playerPosX += (896 + player->getX());

    _playerTexture->render(renderer, playerPosX, player->getY(), player->getWidth(), player->getHeight());


    //Render health bar
    _healthBarTextTexture->render(renderer, 10, 10, _healthBarTextTexture->getWidth(), _healthBarTextTexture->getHeight());

    if (player->getHealth() > 0)
    {
	_healthBarTexture->render(renderer,  _healthBarTextTexture->getWidth() + 13, 10, player->getHealth(), 16);
    }

    //Render score
    delete _scoreTexture; //free the old texture
    _scoreTexture = _rm->loadTexture(std::to_string(player->getScore()), SDL_Color{0, 180, 0});
       
    _scoreTextTexture->render(renderer, 10, 30, _scoreTextTexture->getWidth(), _scoreTextTexture->getHeight());
    _scoreTexture->render(renderer, _scoreTextTexture->getWidth() + 13, 30, _scoreTexture->getWidth(), _scoreTexture->getHeight());

    delete _lastHighestScoreTexture; //free the old texture
    _lastHighestScoreTexture = _rm->loadTexture(std::to_string(player->getHighscore()), SDL_Color{ 0, 180, 0 });

    _lastHighestScoreTextTexture->render(renderer, 10, 70, _lastHighestScoreTextTexture->getWidth(), _lastHighestScoreTextTexture->getHeight());
    _lastHighestScoreTexture->render(renderer, _lastHighestScoreTextTexture->getWidth() + 13, 70, _lastHighestScoreTexture->getWidth(), _lastHighestScoreTexture->getHeight());

    delete _lastScoreTexture; //free the old texture
    _lastScoreTexture = _rm->loadTexture(std::to_string(player->getLastScore()), SDL_Color{ 0, 180, 0 });

    _lastScoreTextTexture->render(renderer, 10, 50, _lastScoreTextTexture->getWidth(), _lastScoreTextTexture->getHeight());
    _lastScoreTexture->render(renderer, _lastScoreTextTexture->getWidth() + 13, 50, _lastScoreTexture->getWidth(), _lastScoreTexture->getHeight());
    
    // Render power up
    renderPowerUps(player->getPowerUps(), renderer);
}


void PlayerRenderer::renderPowerUps(std::vector<PowerUp*> powerUps, SDL_Renderer* renderer)
{
    int powerUpY = 0;

    for (PowerUp* p : powerUps)
    {
	if (p->isActive())
	{
	    if (dynamic_cast<SpeedBoost*>(p))
	    {
		_speedBoostTimerTexture->render(renderer, 259 + 197, 430 + powerUpY, p->getTimer() / 100, _speedBoostTimerTexture->getHeight());
		_speedBoostTimerTextTexture->render(renderer, 256, 430 + powerUpY, _speedBoostTimerTextTexture->getWidth(), _speedBoostTimerTextTexture->getHeight());
	    }
	    else if (dynamic_cast<DoubleJump*>(p))
	    {
		_doubleJumpTimerTexture->render(renderer, 259 + 197, 430 + powerUpY, p->getTimer() / 100, _doubleJumpTimerTexture->getHeight());
		_doubleJumpTimerTextTexture->render(renderer, 256, 430 + powerUpY, _doubleJumpTimerTextTexture->getWidth(), _doubleJumpTimerTextTexture->getHeight());
	    }
	    else if (dynamic_cast<GlideJump*>(p))
	    {
		_glideJumpTimerTexture->render(renderer, 259 + 197, 430 + powerUpY, p->getTimer() / 100, _glideJumpTimerTexture->getHeight());
		_glideJumpTimerTextTexture->render(renderer, 256, 430 + powerUpY, _glideJumpTimerTextTexture->getWidth(), _glideJumpTimerTextTexture->getHeight());
	    }
	}

	powerUpY += 25;
    }
}
