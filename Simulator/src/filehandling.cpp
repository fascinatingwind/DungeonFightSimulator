#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "filehandling.h"
#include "parser.h"

#include "character.h"
#include "action.h"
#include "dice.h"


CharSheet readCharacter(const std::string & fileName)
{
    CharSheet character;
    Parser parser(fileName);
    
    
    //Parsing fileStream for name, class and race
    character.name_  = parser.parseStreamForNextItem<std::string>();
    character.race_  = parser.parseStreamForNextItem<std::string>();
    character.class_ = parser.parseStreamForNextItem<std::string>();
    
    
    //Parsing fileStream for stats
    character.str_ = parser.parseStreamForNextItem<int>();
    character.dex_ = parser.parseStreamForNextItem<int>();
    character.cns_ = parser.parseStreamForNextItem<int>();
    character.int_ = parser.parseStreamForNextItem<int>();
    character.wis_ = parser.parseStreamForNextItem<int>();
    character.chr_ = parser.parseStreamForNextItem<int>();
    
    
    //Parsing fileStream for savethrows
    character.stStr_ = parser.parseStreamForNextItem<Dice>();
    character.stDex_ = parser.parseStreamForNextItem<Dice>();
    character.stCns_ = parser.parseStreamForNextItem<Dice>();
    character.stInt_ = parser.parseStreamForNextItem<Dice>();
    character.stWis_ = parser.parseStreamForNextItem<Dice>();
    character.stChr_ = parser.parseStreamForNextItem<Dice>();
    

    //Parsing fileStream for hp information
    character.hp_        = parser.parseStreamForNextItem<int>();
    character.maxHp_     = parser.parseStreamForNextItem<int>();
    character.tempHp_    = parser.parseStreamForNextItem<int>();
    
    
    //Parsing additional battle stats
    character.ac_        = parser.parseStreamForNextItem<int>();
    character.initBonus_ = parser.parseStreamForNextItem<int>();
    character.speed_     = parser.parseStreamForNextItem<int>();
    
    parser.skipLine();
    
    parser.skipLine();//skipping additional row
    
    while(!parser.isEndOfFile())
    {
        character.actions_.push_back(parser.parseStreamForNextItem<Action>());
    }
    
    return character;
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
