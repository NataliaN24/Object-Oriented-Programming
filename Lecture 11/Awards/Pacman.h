#pragma once
#include"Award.h"

constexpr size_t MAX_POINTS_PACMAN = 150;

class Pacman:public Award
{
public:
	Pacman() = default;
	Pacman(size_t pr);
	void visualize()const override;
};

