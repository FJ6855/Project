#include <vector>

#include "Score.h"
#include "ResourceManager.h"
#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

class HighScore
{
 public:
  HighScore(ResourceManager*);

  ~HighScore();

  void newHighScoreSet();
  bool compare(int);
  void loadScores(ResourceManager* rm);
  void saveScores(ResourceManager* rm);
  void setCurrentScore(int score);
  void setCurrentName(std::string name);
  std::vector<Score*> getScores();

 private:
  std::vector<Score*> _scores;
  ResourceManager* _rm;
  int _currentScore;
  std::string _currentName;

};
#endif
