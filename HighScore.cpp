#include "HighScore.h"
#include <fstream>
#include <iostream>
#include <algorithm>

HighScore::HighScore(ResourceManager* rm)
{
    _rm = rm;
    loadScores(rm);
}
HighScore::~HighScore()
{}

void HighScore::newHighScoreSet()
{
    _scores.push_back(new Score{0, _currentName, _currentScore});
    std::sort(begin(_scores), end( _scores), [](Score* s1, Score* s2) { return s1->getScore() > s2->getScore();} );

    for(int i = 0; i < _scores.size(); ++i)
    {
	_scores[i]->setPos(i+1);
    }

    if(_scores.size() > 10)
    {
	delete _scores.back();
	_scores.pop_back();
    }
}

bool HighScore::compare(int score)
{
    if(_scores.empty() || _scores.size() < 10)
	return true;
  
    for(int i = 0; i < _scores.size(); ++i)
    {
	if(score > _scores[i]->getScore())
	{
	    return true;
	}
    }
    return false;
}

void HighScore::loadScores(ResourceManager* rm)
{
    //loadscores from res/HighScore.txt  
    std::ifstream file("./res/HighScore.txt");

    if (file.is_open())
    {
	std::string name;
	int x{1}, score;

	while (file >> score)
	{
	    getline(file, name);
	    name.erase(begin(name));
	    _scores.push_back( new Score{x, name, score} );
	    x++;
	}

	std::sort(begin(_scores),end(_scores),[](Score* s1, Score* s2) { return s1->getScore() > s2->getScore();});
	
	while (_scores.size() > 10)
	{
	    delete _scores.back();
	    _scores.pop_back();
	}

	file.close();
    }
    else
    {
	std::cout << "Could not open file HighScore.txt" << std::endl;
    }

}

void HighScore::saveScores(ResourceManager* rm)
{
    std::ofstream file("./res/HighScore.txt");

    if (file.is_open())
    {
	for (int i{}; i < _scores.size(); ++i)
	{
	    file << _scores[i]->getScore() << " " << _scores[i]->getName() << std::endl;
	}
	file.close();
    }
    else
    {
	std::cout << "Could not open file HighScore.txt" << std::endl;
    }
}

void HighScore::setCurrentScore(int score)
{
    _currentScore = score;
}

void HighScore::setCurrentName(std::string name)
{
    _currentName = name;
}

std::vector<Score*> HighScore::getScores()
{
    return _scores;
}
