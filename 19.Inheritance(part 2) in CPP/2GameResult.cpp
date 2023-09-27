#include<iostream>
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
class GameResult : public Game
{
private:
    int result[5];

public:
    static const int WIN = 2, LOOSE = 0, DRAW = 1;
    void setResult(int round, int result)
    {
        this->result[round - 1] = result;
    }
    int getResult(int round)
    {
        return result[round - 1];
    }
    void finalResult()
    {
        int scoreSum = 0, resultSum = 0;
        for (int i = 0; i <= 4; i++)
        {
            resultSum += result[i];
            scoreSum += getScore(i + 1);
        }
        cout << "\nTotal Score=" << scoreSum;
        cout << "\nTotal Result Points=" << resultSum;
    }
};
int main()
{
    GameResult gameResult;

    // Setting scores for each round
    for (int round = 1; round <= 5; round++)
    {
        int score;
        cout << "Enter score for Round " << round << ": ";
        cin >> score;
        gameResult.setScore(round, score);
    }

    // Setting results for each round
    for (int round = 1; round <= 5; round++)
    {
        int result;
        cout << "Enter result for Round " << round << " (0 for LOOSE, 1 for DRAW, 2 for WIN): ";
        cin >> result;
        gameResult.setResult(round, result);
    }

    // Displaying final results
    gameResult.finalResult();

    return 0;
}