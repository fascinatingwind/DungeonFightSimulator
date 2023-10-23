#include <cstdlib>
#include <iostream>

#include "action.h"
#include "character.h"
#include "dice.h"
#include "main.h"
#include "filehandling.h"

int main(int argc, char* argv[])
{
    //diceTest();
    readCharacter("../characters/Johny.txt");
    return EXIT_SUCCESS;
}

void diceTest()
{
    std::cout << "ROLLING DICE TEST" << std::endl;

    std::cout << "Simple 1d20 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << Dice().roll() << std::endl;


    std::cout << "------------------------------" << std::endl;
    std::cout << "2d6 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << Dice(2,6).roll() << std::endl;


    std::cout << "------------------------------" << std::endl;
    std::cout << "8d12 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
        std::cout << "result of dice.roll is " << Dice(8,12).roll() << std::endl;


    std::cout << "------------------------------" << std::endl;
    std::cout << "1d2+10 dice testing ::" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout<<"result of dice.roll is " << Dice(1,2,10).roll() <<std::endl;
    }

    std::cout << "ROLLING DICE TEST END" << std::endl;
}
