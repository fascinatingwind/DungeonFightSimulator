#pragma once
#include <string>
#include <vector>

#include "action.h"
#include "diceroll.h"

struct CharSheet
{
    std::string name_;      //maybe some better string type ?
    std::string race_;      //maybe special class for race_ ? enum ?
    std::string class_;     //maybe special class for class_ ? enum ?

    //Stats fields
    int str_;   //strength
    int dex_;   //dexterity
    int cns_;   //constituion
    int int_;   //intellegence
    int wis_;   //wisdom
    int chr_;   //charisma

    //Saving throws
    DiceRoll stStr_;
    DiceRoll stDex_;
    DiceRoll stCns_;
    DiceRoll stInt_;
    DiceRoll stWis_;
    DiceRoll stChr_;

    //HP fields
    int hp_;
    int maxHp_;
    //DiceRoll  _hpDice; need to think if hp dice is essential for combat
    int tempHp_;

    //Battle stats fields
    int ac_;        //armor class
    int initBonus_; //initiative bonus
    int speed_;     //character speed

    //action list (maybe another container ???)
    std::vector<Action> actions_;
};
