#include "Penguin.h"

Penguin::Penguin(size_t pr):Award(pr, MAX_POINTS_PENGUIN)
{
}

void Penguin::visualize() const
{
	std::cout << "Reward: Penguin, Price: " << getPrice() << ", Points: " << getPoints() << std::endl;
}
