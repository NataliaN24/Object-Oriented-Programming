#pragma once
#include"Award.h"

constexpr size_t MAX_POINTS_PENGUIN = 50;

class Penguin:public Award
{
public:
	Penguin() = default;
	Penguin(size_t pr);
	void visualize()const override;
};

