#pragma once
#include"Object.h"

class Paper:public Object
{
public:
	virtual void fight(const Object* other)const override;
	virtual void fightWithPaper(const Paper* other)const override;
	virtual void fightWithScissor(const Scissors* other)const override;
	virtual void fightWithStone(const Stone* other)const override;
};

