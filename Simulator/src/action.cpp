#include "action.h"


Action::Action(const std::string &actionName, Dice damage, Dice attack) : actionName_(actionName), damage_(damage), attack_(attack) {}
