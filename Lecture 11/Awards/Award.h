#pragma once
#include<iostream>

class Award
{
	size_t price;
	size_t points;

public:
	Award();
	Award(size_t pr, size_t pt);
	
	size_t getPrice()const;
	size_t getPoints()const;

	virtual void visualize()const=0;
	virtual ~Award() = default;
};

