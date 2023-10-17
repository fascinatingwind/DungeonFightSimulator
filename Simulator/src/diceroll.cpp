#include <random>
#include "diceroll.h"

DiceRoll::DiceRoll() : diceCount_(1), diceValue_(20), diceBonus_(0){}

DiceRoll::DiceRoll(int diceCount, int diceValue):
    diceCount_(diceCount), diceValue_(diceValue), diceBonus_(0){}

DiceRoll::DiceRoll(int diceCount, int diceValue, int diceBonus):
    diceCount_(diceCount), diceValue_(diceValue), diceBonus_(diceBonus){}

int DiceRoll::roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, diceValue_);

    int sum = diceBonus_;

    for(int i = 0; i < diceCount_; i++)
        sum += distrib(gen);

    return sum;
}
