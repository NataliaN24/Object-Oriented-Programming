#include "Stone.h"

void Stone::fight(const Object* other) const
{
	other->fightWithStone(this);
}

void Stone::fightWithPaper(const Paper* other) const
{
	std::cout << "Paper won";
}

void Stone::fightWithScissor(const Scissors* other) const
{
	std::cout << "Stone won";
}

void Stone::fightWithStone(const Stone* other) const
{
	std::cout << "None won";
}
