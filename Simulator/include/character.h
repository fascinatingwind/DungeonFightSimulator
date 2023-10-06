#pragma once
#include <string>
#include "action.h"
#include "diceroll.h"

struct CharSheet
{
    std::string name; //maybe some better string type ?
    std::string race; //maybe special class for race ?
    std::string class; //maybe special class for class ?

    //Stats fields
    int _str;//strength 
    int _dex;//dexterity
    int _cns;//constituion
    int _int;//intellegence
    int _wis;//wisdom
    int _chr;//charisma

    //Saving throws
    DiceRoll _StStr;
    DiceRoll _StDex;
    DiceRoll _StCns;
    DiceRoll _StInt;
    DiceRoll _StWis;
    DiceRoll _StChr;

    //HP fields
    int _hp;
    int _maxHp;
    //DiceRoll  _hpDice; //2d8 => (2,8)
    int _tempHp;

    //Battle stats fields
    int _ac;//armor class
    int _initBonus; //initiative bonus
    int _speed;

    //action list (maybe another container ???)
    std::vector<Action> _actions;
}
