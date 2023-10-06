#pragma once
#include<tuple>

struct DiceRoll
{
    std::tuple<int, int, int> _dice; //2d8+3 => (2,8,3)
};
