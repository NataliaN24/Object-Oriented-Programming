#pragma once
constexpr unsigned N = 100;

class MapKey0toN
{
	unsigned values[N];
	unsigned nullValue;
public:

	MapKey0toN(unsigned nullValue);

	void add(unsigned key, unsigned value);
	bool contains(unsigned key)const;
	unsigned getValue(unsigned key)const;
};