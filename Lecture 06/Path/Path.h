#pragma once
#include"Town.h"
//Нека имаме произволен брой градове Town.Всеки град е номериран с число id.Път наричаме
//редица от вида[t1, t2, ..., tn] където t1 < t2 ... < tn.Да се създаде система за работа с такива пътища,
//	която поддържа следните функционалности :
//
//Добавяне на град към пътя, като запазвате текущата подредба
//Премахване на град от пътя, като запазвате текущата подредба
//Проверка дали градът ще бъде посетен от пътя
//Обединение на два пътя
//Сечение на два пътя
//Дали два пътя имат общи градове
//Дали има някакви градове в пътя
//Дали съществува град по подадено id(нека търсенето бъде оптимално откъм сложност)
//Колко са градовете в пътя
//Вземане на всички градове като масив от индексите им

class Path
{
	Town* towns;
	size_t count;
	size_t capacity;

	void copyFrom(const Path& other);
	void free();
	void resize(unsigned int newCap);

public:
	Path();
	Path(const Path& other);
	Path& operator=(const Path& other);
	~Path();

	int getIndexOfTown(const Town& other)const;
	void addTown(const Town& newTown);
	void removeTown(const Town& newTown);
	bool isCityInPath(const Town& town)const;
	Path unionPaths(const Path&rhs);
	Path intersectionPaths(const Path&rhs);
	bool doHaveMutualTowns(const Path& p1, const Path& p2)const;
	bool areThereAnyTowns()const;
	bool existsTown(unsigned int id)const;
	unsigned int howManyTowns()const;
	void print()const;

};

