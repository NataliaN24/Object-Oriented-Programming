#pragma once
#include <fstream>
#include "GameObject.h"

Scissors* createScissors(std::ifstream& ifs);
Rock* createRock(std::ifstream& ifs);
Paper* createPaper(std::ifstream& ifs);
GameObject* gameObjFactory(std::ifstream& ifs);