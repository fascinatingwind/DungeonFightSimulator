#include <iostream>
#include "diceroll.h"

int main()
{
    std::cout << "ROLLING DICE TEST" << std::endl;
    
    std::cout << "Simple 1d20 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << DiceRoll().roll() << std::endl;


    std::cout << "------------------------------" << std::endl;
    std::cout << "2d6 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << DiceRoll(2,6).roll() << std::endl;


    std::cout << "------------------------------" << std::endl;
    std::cout << "8d12 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << DiceRoll(8,12).roll() << std::endl;

    
    std::cout << "------------------------------" << std::endl;
    std::cout << "1d2+10 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout<<"result of dice.roll is " << DiceRoll(1,2,10).roll() <<std::endl;
    }

    std::cout << "ROLLING DICE TEST END" << std::endl;
}