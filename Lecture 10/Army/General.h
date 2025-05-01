#pragma once
#include"Soldier.h"
#include"Commander.h"

class General:public Soldier
{
	Commander* commanders;
	size_t count;
	char* description;

	void copyFrom(const General& other);
	void free();
public:
	General();
	General(const char* name, size_t age, size_t combat, size_t salary,
		const char* description, const Commander* commanders, size_t count);
	General(const General& other);
	General& operator=(const General& other);
	~General();

	void printArmy(std::ostream& os)const;

};

