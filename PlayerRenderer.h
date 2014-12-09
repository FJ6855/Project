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
	 loadContent();
	 _playerFrame = 0;
  }
  ~PlayerRenderer();

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
	Texture* _scoreTexture = nullptr;
	Texture* _scoreTextTexture;

	Texture* _lastHighestScoreTexture = nullptr;
	Texture* _lastHighestScoreTextTexture;

	Texture* _lastScoreTexture = nullptr;
	Texture* _lastScoreTextTexture;

	// Textures for power ups
	Texture* _speedBoostTimerTexture = nullptr;
	Texture* _doubleJumpTimerTexture = nullptr;
	Texture* _glideJumpTimerTexture = nullptr;

	Texture* _speedBoostTimerTextTexture = nullptr;
	Texture* _doubleJumpTimerTextTexture = nullptr;
	Texture* _glideJumpTimerTextTexture = nullptr;
	
	int _playerFrame;

	void renderPowerUps(std::vector<PowerUp*> powerUps, SDL_Renderer* renderer);
};

#endif
