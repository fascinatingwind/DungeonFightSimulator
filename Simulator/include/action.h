#pragma once
#include"diceroll.h"
#include"character.h"
#include<string>

class Action
{
    std::string actionName_;
    DiceRoll damage_;
    DiceRoll attack_;

public:
    Action(std::string actionName_, DiceRoll damage_, DiceRoll attack_);
    void useOn(CharSheet& targetChar, int attackBonus = 0, int damage_bonus = 0);
};

Action actionFactory(std::string actionName_);
