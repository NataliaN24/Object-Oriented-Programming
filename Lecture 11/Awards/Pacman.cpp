#include "Pacman.h"

Pacman::Pacman(size_t pr):Award(pr, MAX_POINTS_PACMAN)
{
}

void Pacman::visualize() const
{
	std::cout << "Reward: Penguin, Price: " << getPrice() << ", Points: " << getPoints() << std::endl;
}
