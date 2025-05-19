#include "Paper.h"

void Paper::fight(const Object* other) const
{
	other->fightWithPaper(this);
}

void Paper::fightWithPaper(const Paper* other) const
{
	std::cout << "None won";
}

void Paper::fightWithScissor(const Scissors* other) const
{
	std::cout << "Scissor won";
}

void Paper::fightWithStone(const Stone* other) const
{
	std::cout << "Paper won";
}
