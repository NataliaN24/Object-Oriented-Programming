#include "Scissors.h"

void Scissors::fight(const Object* other) const
{
	other->fightWithScissor(this);
}

void Scissors::fightWithPaper(const Paper* other) const
{
	std::cout << "Scissors won";
}

void Scissors::fightWithScissor(const Scissors* other) const
{
	std::cout << "None won";
}

void Scissors::fightWithStone(const Stone* other) const
{
	std::cout << "Stone won";
}
