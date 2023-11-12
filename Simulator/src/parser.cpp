#include"parser.h"
#include<fstream>

Parser::Parser(const std::string & fileName) : fileStream_(fileName)
{
    if(!fileStream_)
        throw std::invalid_argument("there is no such file as " + fileName);
}

template <>
int Parser::parseStreamForNextItem()
{
    int answer;
    fileStream_ >> answer;
    return answer;
}

template <>
std::string Parser::parseStreamForNextItem()
{
    std::string tmpString;
    std::getline(fileStream_, tmpString);
    return tmpString;
}

template<>
Dice Parser::parseStreamForNextItem()
{
    int diceBonus;
    fileStream_ >> diceBonus;
    return Dice(1, 20, diceBonus);
}

template<>
Action Parser::parseStreamForNextItem()
{
    std::string action_name;
    int atkCount, atkValue, atkBonus; //параметры для кубика атаки
    int dmgCount, dmgValue, dmgBonus; //параметры для кубика урона
    
    std::getline(fileStream_, action_name);
    
    fileStream_ >> atkCount;
    fileStream_ >> atkValue;
    fileStream_ >> atkBonus;
    fileStream_ >> dmgCount;
    fileStream_ >> dmgValue;
    fileStream_ >> dmgBonus;
    
    this->skipLine();
    this->skipLine();
    
    return Action(action_name, Dice(dmgCount, dmgValue, dmgBonus), Dice(atkCount, atkValue, atkBonus));
}

bool Parser::isEndOfFile()
{
    if(fileStream_)
        return true;
    
    return false;
}

void Parser::skipLine()
{
    fileStream_.get();
}
