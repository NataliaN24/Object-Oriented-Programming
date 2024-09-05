#include "Scissors.h"

Scissors::Scissors(int val):value(val)
{
}

int Scissors::duelAgainst(const GameObject* other) const
{
    return -(other->duelAgainstScissors(this));//it should return a negative int based on requirements
}

int Scissors::duelAgainstRock(const Rock* other) const
{
    return -1;
}

int Scissors::duelAgainstPaper(const Paper* other) const
{
    return 1;
}

int Scissors::duelAgainstScissors(const Scissors* other) const
{
    if (value > other->value)
    {
        return 1;
    }
    if (value < other->value)
    {
        return -1;
    }
    return 0;
}

GameObject* Scissors::clone() const
{
    return new Scissors(*this);
}