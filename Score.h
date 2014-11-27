#ifndef SCORE_H
#define SCORE_H

#include <string>

class Score
{
 public:
 Score(int pos, std::string name, int score) : _pos{pos}, _name{name}, _score{score} {}

  int getPos();
  void setPos(int);
  std::string getName();
  int getScore() const;

 private:
  int _pos;
  std::string _name;
  int _score;
};

#endif
