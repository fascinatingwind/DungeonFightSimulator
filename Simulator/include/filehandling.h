#pragma once

#include <string>

#include "character.h"

CharSheet readCharacter(const std::string & fileName);

void writeCharacter(const CharSheet & character);

