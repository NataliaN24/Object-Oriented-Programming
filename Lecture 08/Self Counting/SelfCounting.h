#pragma once
class SelfCounting
{
	const int constValue;
	static unsigned liveObjCount;
	static unsigned createdCount;

public:
	SelfCounting();
	SelfCounting(int value);
	SelfCounting(const SelfCounting& other);
	~SelfCounting();

	static unsigned getLiveObjCout();
	static unsigned getCreatedCount();
};