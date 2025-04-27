#pragma once
#include"Student.h"

constexpr int MaxStudentsInClass = 15;
class Classroom
{
	Student** students;
	int count;
	int capacity;

	void copyFrom(const Classroom& other);
	void free();
	void moveFrom(Classroom&& other);
	void resize(int newCap);

public:
	Classroom();
	Classroom(int cap);
	Classroom(const Classroom& other);
	Classroom(Classroom&& other);
	Classroom& operator=(const Classroom& other);
	Classroom& operator=(Classroom&& other);
	~Classroom();

	void dropStudent(int index);
	int howManyFreeSeats()const;
	int getEmptiestRow(int row,int count);
	void swapStudents(int index1, int index2);
	void addStudent(int index,const Student&st);
	void addStudent(int index, Student&& st);

	int getCount()const;
	int getCapacity()const;

	void print()const;


};

