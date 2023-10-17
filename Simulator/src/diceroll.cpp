#include <random>
#include "diceroll.h"

DiceRoll::DiceRoll() : diceCount_(1), diceValue_(20), diceBonus_(0){}

DiceRoll::DiceRoll(int dicesNum, int dicesSize):
    diceCount_(dices), diceValue_(diceSize), diceBonus_(0){}

DiceRoll::DiceRoll(int dicesNum, int dicesSize, int bonus):
    diceCount_(dices), diceValue_(diceSize), diceBonus_(bonus){}

DiceRoll::roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, diceValue_);

    int sum = bonus;

    for(int i = 0; i < dicesNum; i++)
        sum += distrib(gen);

    return sum;
}
