#include <iostream>
using namespace std;
class Game
{
private:
    int score[5];

public:
    void setScore(int round, int score)
    {
        this->score[round - 1] = score;
    }
    int getScore(int round)
    {
        return score[round - 1];
    }
};
