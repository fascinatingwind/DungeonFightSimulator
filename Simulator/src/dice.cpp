#include <random>
#include "dice.h"

Dice::Dice() : diceCount_(1), diceValue_(20), diceBonus_(0){}

Dice::Dice(int diceCount, int diceValue):
    diceCount_(diceCount), diceValue_(diceValue), diceBonus_(0){}

Dice::Dice(int diceCount, int diceValue, int diceBonus):
    diceCount_(diceCount), diceValue_(diceValue), diceBonus_(diceBonus){}

int Dice::roll()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, diceValue_);

    int sum = diceBonus_;

    for(int i = 0; i < diceCount_; i++)
        sum += distrib(gen);

    return sum;
}

int Dice::getBonus() const
{
    return diceBonus_;
}
std::ostream& operator << (std::ostream & os, const Dice& dice)
{
    return os << dice.diceCount_ << " " <<
                 dice.diceValue_ << " " << dice.diceBonus_;
}
