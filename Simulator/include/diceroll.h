#pragma once

class DiceRoll
{
    int diceCount_;
    int diceValue_;
    int diceBonus_;

public:
    DiceRoll();             //1d20+0
    DiceRoll(int, int);     //diceCount d diceValue + 0
    DiceRoll(int, int, int);//diceCount d diceValue + diceBonus
    roll();
};
