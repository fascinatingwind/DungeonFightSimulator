#pragma once
#include"diceroll.h"
#include<string>

struct Action
{
    std::string actionName_;
    DiceRoll damage_; // starting with constant damage
};
