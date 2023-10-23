#pragma once

#include <string>
#include <fstream>

#include "character.h"
#include "action.h"

CharSheet readCharacter(const std::string & fileName);
//Action readAction(std::ifstream & openFile);
