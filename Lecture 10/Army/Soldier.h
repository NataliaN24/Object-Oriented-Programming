#pragma once
#include<iostream>
#pragma warning(disable:4996)

class Soldier
{
protected:
	char* name;
	size_t age;
	size_t combatSkills;
	size_t salary;

	void free();
	void copyFrom(const Soldier& other);

public:
	Soldier();
	Soldier(const char*name,size_t age,size_t combat,size_t salary);
	Soldier(const Soldier& other);
	Soldier& operator=(const Soldier& other);
	virtual ~Soldier();

	const char* getName() const;
	size_t getAge() const;
	size_t getCombatSkills() const;
	size_t getSalary() const;

	void setName(const char* newName);
	void setAge(size_t newAge);
	void setCombatSkills(size_t newSkills);
	void setSalary(size_t newSalary);

	virtual void print() const;

};
