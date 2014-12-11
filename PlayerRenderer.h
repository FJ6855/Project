#include <vector>

#include "Renderer.h"
#include "ResourceManager.h"
#include "Player.h"
#include "PowerUp.h"

#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

class PlayerRenderer : public Renderer
{
public:
    PlayerRenderer(ResourceManager* rm) : Renderer{rm}
    {
	// need to set pointers that we delete in the render function
	_playerTexture = nullptr;
	_scoreTexture = nullptr;
	_lastHighestScoreTexture = nullptr;
	_lastScoreTexture = nullptr;
	_currentDifficultyNumberTexture = nullptr; 

	_playerFrame = 0;

	loadContent();
    }

    ~PlayerRenderer()
    {
	// dont need to delete _playerTexture because it will be pointing to one of the textures in the vector or the following textures
	_playerTexture = nullptr;

	delete _playerTextureInAirRight;
	_playerTextureInAirRight = nullptr;
	delete _playerTextureInAirLeft;
	_playerTextureInAirLeft = nullptr;

	delete _healthBarTexture;
	_healthBarTexture = nullptr;
	delete _healthBarTextTexture;
	_healthBarTextTexture = nullptr;

	delete _scoreTexture;
	_scoreTexture = nullptr;
	delete _scoreTextTexture;
	_scoreTextTexture = nullptr;

	delete _lastHighestScoreTexture;
	_lastHighestScoreTexture = nullptr;
	delete _lastHighestScoreTextTexture;
	_lastHighestScoreTextTexture = nullptr;

	delete _lastScoreTexture;
	_lastScoreTexture = nullptr;
	delete _lastScoreTextTexture;
	_lastScoreTextTexture = nullptr;

	delete _speedBoostTimerTexture;
	_speedBoostTimerTexture = nullptr;
	delete _doubleJumpTimerTexture;
	_doubleJumpTimerTexture = nullptr;
	delete _glideJumpTimerTexture;
	_glideJumpTimerTexture = nullptr;

	delete _speedBoostTimerTextTexture;
	_speedBoostTimerTextTexture = nullptr;
	delete _doubleJumpTimerTextTexture;
	_doubleJumpTimerTextTexture = nullptr;
	delete _glideJumpTimerTextTexture;
	_glideJumpTimerTextTexture = nullptr;

	delete _currentDifficultyTextTexture;
	_currentDifficultyTextTexture = nullptr;
	delete _currentDifficultyNumberTexture;
	_currentDifficultyNumberTexture = nullptr; 
    }

    void loadContent() override;
    void render(Player* player, SDL_Renderer* renderer);

private:
    //Player sprites in the air
    Texture* _playerTextureInAirRight;
    Texture* _playerTextureInAirLeft;

    //The texture that is rendered every time. Will be pointing to one of the textures above
    Texture* _playerTexture;

    //Textures for health bar
    Texture* _healthBarTexture;
    Texture* _healthBarTextTexture;

    //Textures for the score
    Texture* _scoreTexture;
    Texture* _scoreTextTexture;

    Texture* _lastHighestScoreTexture;
    Texture* _lastHighestScoreTextTexture;

    Texture* _lastScoreTexture;
    Texture* _lastScoreTextTexture;

    // Textures for power ups
    Texture* _speedBoostTimerTexture;
    Texture* _doubleJumpTimerTexture;
    Texture* _glideJumpTimerTexture;

    Texture* _speedBoostTimerTextTexture;
    Texture* _doubleJumpTimerTextTexture;
    Texture* _glideJumpTimerTextTexture;
	
    //Texture for current difficulty
    Texture* _currentDifficultyTextTexture;
    Texture* _currentDifficultyNumberTexture;

    int _playerFrame;

    void renderPowerUps(std::vector<PowerUp*> powerUps, SDL_Renderer* renderer);
};

#endif
