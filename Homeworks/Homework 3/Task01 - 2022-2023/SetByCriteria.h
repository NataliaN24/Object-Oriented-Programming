#pragma once
#include"Set.h"
#include"MyString.h"
#include"UnionOfSets.h"
#include"InteresectionOfSets.h"
#include<cstring>
#include<fstream>

#pragma warning(disable :4996)

class SetByCriteria:public Set
{
private:

	bool (*predicate)(int, const int*, int);
	int* elements;
	int size;
	int currentIndex;

	void copyFrom(const  SetByCriteria& other);
	void moveFrom(SetByCriteria&& other)noexcept;
	void free();

public:
	SetByCriteria();
	SetByCriteria(const SetByCriteria& other);
	SetByCriteria(SetByCriteria&& other)noexcept;
	SetByCriteria& operator=(const SetByCriteria& other);
	SetByCriteria& operator=(SetByCriteria&& other)noexcept;
	SetByCriteria(bool (*pred)(int, const int*, int),  int* elems, int sz);

	bool contains(int element) const override ;
	int nextElement() override;
	
};

bool isElementInFiniteSet(int element, const int* elements, int size);
bool isElementNotDivisible(int element, const int* elements, int size);
bool isElementDivisibleByOne(int element, const int* elements, int size);
void outputNumbersInInterval(const Set*set);
void generateSequentially( Set*set);

Set* createSetFromFile(MyString& filename);
Set* finiteSet(std::ifstream& file, uint16_t N);
Set* notDivisible(std::ifstream& file, uint16_t N);
Set* divisible(std::ifstream& file, uint16_t N);
Set* pathUnion(std::ifstream& file, uint16_t N);
Set* pathIntersection(std::ifstream& file, uint16_t N);