#pragma once
#include"Soldier.h"

class Commander:public Soldier
{
	Soldier* soldiers;
	size_t count;
	void copyFrom(const Commander& other);
	void free();
public:
	Commander();
	Commander(const char* name, size_t age, size_t combat, size_t salary, size_t count,const Soldier*battalion);
	Commander(const Commander&other);
	Commander& operator=(const Commander& other);
	~Commander();

	void setBattalion(const Soldier* soldiers, size_t count);
	Soldier* getBattalion()const;
	size_t getNumOfSoldiers()const;

	void print()const override;

};

