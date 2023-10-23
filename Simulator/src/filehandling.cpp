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
    
    file >> atkCount;
    file >> atkValue;
    file >> atkBonus;
    file >> dmgCount;
    file >> dmgValue;
    file >> dmgBonus;
    file.get();
    
    file.get(); //skipping additional row
    
    
    return Action(action_name, Dice(dmgCount, dmgValue, dmgBonus), Dice(atkCount, atkValue, atkBonus));
}

void writeCharacter(const CharSheet & character)
{
    std::string fileName("../characters/" + character.name_ + ".txt");
    std::ofstream file;
    
    file.open(fileName, std::ios::out | std::ios::trunc);

    file << character.name_  << std::endl;
    file << character.race_  << std::endl;
    file << character.class_ << std::endl;
    
    file << character.str_ << " " << character.dex_ << " " <<
            character.cns_ << " " << character.int_ << " " <<
            character.wis_ << " " << character.chr_ << std::endl;
    
    file << character.stStr_.getBonus() << " " <<                     character.stDex_.getBonus() << " " <<
            character.stCns_.getBonus() << " " <<
            character.stInt_.getBonus() << " " <<
            character.stWis_.getBonus() << " " <<
            character.stChr_.getBonus() << std::endl;
    
    file << character.hp_ << " " << character.maxHp_ << " " <<
            character.tempHp_ << std::endl;
    
    file << character.ac_ << " " << character.initBonus_ << " " <<
            character.speed_ << std::endl;
    
    for(auto & action : character.actions_)
        file << action;
    file.close();
}
