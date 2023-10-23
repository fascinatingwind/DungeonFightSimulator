#pragma once
#include "dice.h"
#include <string>

//forward declaration
class CharSheet;

class Action
{
    std::string actionName_;
    Dice damage_;
    Dice attack_;

public:
    Action(const std::string & actionName, Dice damage, Dice attack);
    void useOn(CharSheet& targetChar, int attackBonus = 0, int damageBonus = 0);
};
