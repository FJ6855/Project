#include <vector>

#include "Score.h"
#include "ResourceManager.h"
#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

class HighScore
{
 public:
  HighScore()
    {
      _currentScore = 0;
      _currentName = "";
    }

  void newHighScoreSet();
  void compare(int score);
  int  getScore();
  void loadScores(ResourceManager* rm);
  void saveScores(ResourceManager* rm);
  void setCurrentScore(int score);
  void setCurrentName(std::string name);

 private:
  std::vector<Score> _scores;
  bool _newHighScoreSet;
  int _currentScore;
  std::string _currentName;
};

#endif
