#pragma once
#include"diceroll.h"
#include<string>
struct Action
{
    std::string _action_name;
    DiceRoll _damage; // starting with constant damage
};
