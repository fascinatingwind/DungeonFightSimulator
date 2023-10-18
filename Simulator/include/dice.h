#pragma once

class Dice
{
    int diceCount_;
    int diceValue_;
    int diceBonus_;

public:
    Dice();             //1d20+0
    Dice(int, int);     //diceCount d diceValue + 0
    Dice(int, int, int);//diceCount d diceValue + diceBonus
    int roll();
};
