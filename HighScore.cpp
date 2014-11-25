#include "HighScore.h"

void HighScore::newHighScoreSet()
{
  //???????? 
}
int HighScore::getScore()
{
  return _currentScore;
}

void HighScore::compare(int score)
{

}

void HighScore::loadScores(ResourceManager* rm)
{
  
}

void HighScore::saveScores(ResourceManager* rm)
{
  
}

void HighScore::setCurrentScore(int score)
{
  _currentScore = score;
}

void HighScore::setCurrentName(std::string name)
{
  _currentName = name;
}
