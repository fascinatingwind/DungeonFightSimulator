#include "action.h"


Action::Action(const std::string &actionName, Dice damage, Dice attack) : actionName_(actionName), damage_(damage), attack_(attack) {}

std::ostream& operator << (std::ostream & os, const Action& action)
{
    return os << std::endl << action.actionName_ << std::endl << action.attack_ << " " << action.damage_ << std::endl;
}
