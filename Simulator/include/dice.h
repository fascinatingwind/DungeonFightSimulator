#pragma once
#include<iostream>

class Dice
{
    int diceCount_;
    int diceValue_;
    int diceBonus_;

public:
    Dice();             //1d20+0
    Dice(int, int);     //diceCount d diceValue + 0
    Dice(int, int, int);//diceCount d diceValue + diceBonus
    int getBonus() const;
    int roll();
    
    friend std::ostream& operator << (std::ostream & os, const Dice& dice);
};
