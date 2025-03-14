#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

//Ще създадем проста система за работа със задачи.Всяка задача се състои от :
//
//Име, с произволна дължина.
//Условие, с произволна дължина.
//Цяло число, показващо колко точки носи задачата.Също така всяка задача трябва да поддържа следната функционалност :
//Да можем по всяко време да променяме условието на задачата.
//Да можем по всяко време да променяме името на задачата.
//Да можем по всяко време да променяме точките, които задачата носи.
// Създайте структура, моделираща изпит, която поддържа константен брой(20)
//  задачи и цяло число, показващо минималните точки, изискващи се за успешно вземане на изпита.Създайте също :
//Функция за добавяне на задача
//Функция writeToFile(const char* fileName), която записва контролното във файл.
//Функция readFromFile(const char* fileName), която чете контролното от файл.
//Функция changeMin(), която подава нов минимален успех за вземане на изпита.
//Функция getMax(), която извежда максималния брой точки за текущия изпит.

class Task
{
	char* name;
	char* description;
	unsigned int points;

	void free();
	void copyFrom(const Task& other);

public:
	Task();
	Task(const Task& other);
	Task& operator=(const Task& other);
	Task(const char* name, const char* descr, unsigned int p);
	void changeDescription(const char* newDescr);
	void changeName(const char* newName);
	void changePoints(unsigned int newPoints);
	void writeTaskToFile(std::ofstream&ofs)const;
	void readTaskFromFile(std::ifstream&ifs);
	unsigned int getPoints()const;
	~Task();
};

