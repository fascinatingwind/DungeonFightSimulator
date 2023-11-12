#pragma once

#include <fstream>
#include <string>

#include "dice.h"
#include "action.h"

class Parser
{
    
private:
    std::ifstream fileStream_;
    
public:
    Parser(const std::string & fileName);
    
    template<typename T>
    T parseStreamForNextItem();
    
    bool isEndOfFile();
    
    void skipLine();
};


template<>
int Parser::parseStreamForNextItem();

template<>
std::string Parser::parseStreamForNextItem();

template<>
Dice Parser::parseStreamForNextItem();

template<>
Action Parser::parseStreamForNextItem();
