#pragma once
#include "diceroll.h"
#include <string>

//forward declaration
class CharSheet;

class Action
{
    std::string actionName_;
    DiceRoll damage_;
    DiceRoll attack_;

public:
    Action(const std::string & actionName_, DiceRoll damage_, DiceRoll attack_);
    void useOn(CharSheet& targetChar, int attackBonus = 0, int damage_bonus = 0);
};
