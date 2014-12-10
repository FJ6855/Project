#include <string>

#ifndef SCORE_H
#define SCORE_H

class Score
{
public:
    Score(int pos, std::string name, int score) : _pos{pos}, _name{name}, _score{score} {}

    ~Score() = default;

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
