#include <vector>

#include "Object.h"
#include "InputHandler.h"
#include "PowerUp.h"
#include "SpeedBoost.h"
#include "DoubleJump.h"
#include "GlideJump.h"

#ifndef PLAYER_H
#define PLAYER_H

enum PlayerState {
    dead,
    running,
    jumping,
    standing,
    inAir
};

enum PlayerDirection {
    right,
    left
};

class Player : public Object
{
public:
    Player(int x, int y, int width, int height) : Object(x, y, width, height)
    {
	_speed = 8;
	_defaultSpeed = _speed;
	_airSpeed = 0;
	_gravity = 0.45f;
	_xVel = 0;
	_yVel = 0;
	_playerState = inAir;
	_lastPlayerState = _playerState;
	_playerDirection = right;
	_health = 100;
	_score = 0;
	_highscore = 0;
	_scoreOffset = 0;
	_healthLossFactor = 0.05f;
	_jumpBoost = true;
	_jumpBoostGravity = _gravity;
	_canDoubleJump = false;
	_canGlideJump = false;
	_lastScore = 0;
	_movementDifference = 0;   
	_godMode = false;
	_saveHighScore = true;
	_lastX = _x;
	_currentDifficulty = 1;
    }

    ~Player() 
    {
	for (PowerUp* p : _powerUps)
	{
	    delete p;
	    p = nullptr;
	}
    }
    
    Player* clone() const override;

    void reset();

    void handleInput(InputHandler* inputHandler);
    void updateLogic() override;

    void updatePowerUps();

    float getXvel();
    float getYvel();

    float getSpeed();
    void setSpeed(float speed);
    void resetSpeed();

    void setAirSpeed(float airSpeed);
  
    bool getCanDoubleJump();
    void setCanDoubleJump(bool canDoubleJump);

    bool getCanGlideJump();
    void setCanGlideJump(bool canGlideJump);

    void setXvel(int xVel);
    void setYvel(int yVel);

    int getMovementDifference();
    void setMovementDifference(int movementDifference);

    void setState(PlayerState state);
    PlayerState getState();
    void setLastState(PlayerState state);
    PlayerState getLastState();

    void setDirection(PlayerDirection direction);
    PlayerDirection getDirection();

    float getHealth();
    void setHealth(int health);
  
    std::vector<PowerUp*> getPowerUps();
    void addPowerUp(PowerUp* powerUp);

    int getScore();
    void setScore(int score);
    void setHighscore(int highscore);
    int getHighscore();

    void setLastScore(int lastScore);
    int getLastScore();

    void setDifficulty(int difficulty);
    int getDifficulty();

    bool isGod();
    bool getSaveHighScore();

private:
    float _speed;
    float _airSpeed;
    float _defaultSpeed;
    float _gravity;
    float _xVel;
    float _yVel;

    int _lastX;
    int _movementDifference;

    float _health;

    std::vector<PowerUp*> _powerUps;

    int _score;
    int _highscore;
    int _lastScore;
    float _scoreOffset;

    int _currentDifficulty;
    float _healthLossFactor;

    //jump control
    bool _jumpBoost;
    float _jumpBoostGravity;

    bool _canDoubleJump;
    bool _canGlideJump;

    PlayerDirection _playerDirection;
    PlayerState _playerState;
    PlayerState _lastPlayerState;

    // cheat
    bool _godMode;
    bool _saveHighScore;

    void jump();
};

#endif
