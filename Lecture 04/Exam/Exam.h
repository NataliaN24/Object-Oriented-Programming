#pragma once
#include"Task.h"
// Създайте структура, моделираща изпит, която поддържа константен брой(20)
//  задачи и цяло число, показващо минималните точки, изискващи се за успешно вземане на изпита.Създайте също :
//Функция за добавяне на задача
//Функция writeToFile(const char* fileName), която записва контролното във файл.
//Функция readFromFile(const char* fileName), която чете контролното от файл.
//Функция changeMin(), която подава нов минимален успех за вземане на изпита.
//Функция getMax(), която извежда максималния брой точки за текущия изпит.

constexpr int maxTasks = 20;

class Exam
{
	Task tasks[maxTasks];
	size_t countOfTasks;
	size_t minPointsToPass;

public:
	Exam();
	Exam(const Task* tasks, size_t number, size_t points);
	void setTasks(const Task* tasks, size_t count);
	void setMinPoints(size_t newMin);
	void addTask(const Task& newTask);
	void writeToFile(const char* fileName)const ;
	void readFromFile(const char* fileName);
	void changeMin(size_t newMin);
	size_t getMax()const;
};

