#include <string>
#include <fstream>
#include <stdexcept>

#include "filehandling.h"
#include "character.h"
#include "action.h"
#include "vector"

//for test
#include <iostream>
//for test ended

CharSheet readCharacter(const std::string & fileName)
{
    CharSheet character;
    
    int stStr, stDex, stCns, stInt, stWis, stChr;   //бонусы спасбросков

    std::ifstream file(fileName);
    if(!file)
        throw std::invalid_argument("there is no such file as "+fileName);
        
    std::getline(file, character.name_);
    std::getline(file, character.race_);
    std::getline(file, character.class_);

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
    file.get();
    
    file.get(); //skipping additional row
    
    while (file)
        character.actions_.push_back(readAction(file));
    
    file.close();
    
    return character;
}

Action readAction(std::ifstream & file)
{
    std::string action_name;
    int atkCount, atkValue, atkBonus; //параметры для кубика атаки
    int dmgCount, dmgValue, dmgBonus; //параметры для кубика урона
    
    std::getline(file, action_name);
    std::cout<<action_name;
    
    file >> atkCount;
    file >> atkValue;
    file >> atkBonus;
    file >> dmgCount;
    file >> dmgValue;
    file >> dmgBonus;
    file.get();
    
    file.get(); //skipping additional row
    
    
    return Action(action_name, Dice(atkCount, atkValue, atkCount), Dice(dmgCount, dmgValue, dmgBonus));
}
