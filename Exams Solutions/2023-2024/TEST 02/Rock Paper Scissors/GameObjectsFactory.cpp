#include "GameObjectsFactory.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

Scissors* createScissors(std::ifstream& ifs)
{
    int value;
    ifs >> value;
    return new Scissors(value);
}

Rock* createRock(std::ifstream& ifs)
{
    bool value;
    ifs >> value;
    return new Rock(value);
}

Paper* createPaper(std::ifstream& ifs)
{
    char str[1024];
    ifs >> str;
    return new Paper(str);
}

GameObject* gameObjFactory(std::ifstream& ifs)
{
    int code;
    ifs >> code;

    switch (code)
    {
    case 0:
        return createScissors(ifs);
    case 1:
        return createRock(ifs);
    case 2:
        return createPaper(ifs);
    }
    throw std::runtime_error("File data not in correct format");
}