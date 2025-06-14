#pragma once

constexpr int MAX_NUMBERS = 32;
class TinyMultiset
{
	unsigned char count[MAX_NUMBERS] = { 0 };
public:

	void add(int num);
	void remove(int num);
	int operator()(int num)const;
};

