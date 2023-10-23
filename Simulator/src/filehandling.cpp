#include <string>
#include <fstream>
#include <stdexcept>

#include "character.h"
#include "action.h"
#include "vector"

//for test
#include <iostream>
//for test ended

CharSheet readCharacter(const std::string & fileName)
{
    CharSheet character;
    std::string name, race, class_;
    std::vector<Action> actions;
    int str, dex, cns, int_, wis, chr; //бонусы характеристик
    int stStr, stDex, stCns, stInt, stWis, stChr; //бонусы спасбросков
    int hp, maxHp, tempHp; //данные о здоровье
    int ac, initBonus, speed; //данные для боя

    std::ifstream file(fileName);
    if(!file)
        throw std::invalid_argument("there is no such file as "+fileName);
        
    std::getline(file, name);
    std::getline(file, race);
    std::getline(file, class_);

    file >> character.str_;
    file >> character.dex_;
    file >> character.cns_;
    file >> character.int_;
    file >> character.wis_;
    file >> character.chr_;
    
    file >> stStr;
    character.stStr_ = Dice(1, 20, stStr);
    file >> stDex;
    character.stDex_ = Dice(1, 20, stDex);
    file >> stCns;
    character.stCns_ = Dice(1, 20, stCns);
    file >> stInt;
    character.stInt_ = Dice(1, 20, stInt);
    file >> stWis;
    character.stWis_ = Dice(1, 20, stWis);
    file >> stChr;
    character.stChr_ = Dice(1, 20, stChr);
    
    file >> character.hp_;
    file >> character.maxHp_;
    file >> character.tempHp_;
    
    file >> character.ac_;
    file >> character.initBonus_;
    file >> character.speed_;
    
    //Вставить цикл, считывающий действия
    
    file.close();
    
    return character;
}

//Action readAction(std::ifstream & openFile)
//{
//    return Action();
//}
