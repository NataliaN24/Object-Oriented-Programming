#pragma once
#include<iostream>

class Paper;
class Scissors;
class Stone;

class Object
{
public:
	virtual void fight(const Object* other)const=0;
	virtual void fightWithPaper(const Paper* other)const = 0;
	virtual void fightWithScissor(const Scissors* other)const = 0;
	virtual void fightWithStone(const Stone* other)const = 0;

	virtual~Object() = default;
};

