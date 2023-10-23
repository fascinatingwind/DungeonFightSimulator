#include <string>
#include <fstream>

#include "character.h"

//for test
#include <iostream>
//for test ended

CharSheet readCharacter(const std::string & fileName)
{
    //добавить проверку на то открылся ли вообще файл, если нет то выбросить ошибку
    std::string name, race, class_;
    int str, dex, cns, int_, wis, chr; //бонусы характеристик
    int stStr, stDex, stCns, stInt, stWis, stChr; //бонусы спасбросков
    int hp, maxHp, tempHp;
    int ac, initBonus, speed;

    std::ifstream file(fileName);

    std::getline(file, name);
    std::getline(file, race);
    std::getline(file, class_);

    file >> str;
    file >> dex;
    file >> cns;
    file >> int_;
    file >> wis;
    file >> chr;
    
    file >> stStr;
    file >> stDex;
    file >> stCns;
    file >> stInt;
    file >> stWis;
    file >> stChr;	
    
    file >> hp;
    file >> maxHp;
    file >> tempHp;
    
    file >> ac;
    file >> initBonus;
    file >> speed;

    return CharSheet();
}
