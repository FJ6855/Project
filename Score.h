#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score
{
 public:
 Score(int pos, std::string name, int score) : _pos{pos}, _name{name}, _score{score} {}

  int getPos();
  std::string getName();
  int getScore();

 private:
  int _pos;
  std::string _name;
  int _score;
};

#endif
