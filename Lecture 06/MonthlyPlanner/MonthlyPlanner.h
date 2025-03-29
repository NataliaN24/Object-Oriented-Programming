#pragma once
#include"Task.h"

//Реализирайте клас MonthlyPlanner, който описва график със задачи за всеки ден от даден месец.В началото графикът е празен,
//няма съхранени задачи.Дефинирайте метод, 
//чрез който към даден график се добавя задача.Освен задачата, този метод трябва да получава като аргумент за кой ден да бъде тя
//и в кой час да започне.Също така трябва да може да се премахва дадена задача по подаден ден и номер в конкретния ден.За класа
//MonthlyPlanner дефинирайте още следните методи :
//
//метод, който по подаден ден, извежда на екрана всички незавършени задачи, записани за него.
//метод, който по зададен ден и час, маркира като изпълнена задачата, която е планирана в този момент.
//метод за съхранение на данните от един такъв обект в текстов файл, както и метод за прочитане на така записан обект.Приемаме, 
//че за всеки ден максималния брой задачи може да е 10, а всеки месец име 30 дни.
class MonthlyPlanner
{
	static const int DAYS_IN_MONTH = 30;
	static const int MAX_TASKS_PER_DAY = 10;
	Task tasks[DAYS_IN_MONTH][MAX_TASKS_PER_DAY];
	bool isValidDayAndTask(int day, int taskNumber);
public:
	MonthlyPlanner();
	void addTask(int day, const char* description,size_t priority, unsigned int hour);
	void removeTask(int day, int taskNumber);
	void displayUnfinishedTasks(int day)const;
	void markAsCompleted(int day, int taskNumber);
	void saveToFile(const char* filename);
	void loadFromFile(const char* filename);
	void printTasksForDay(int day);

};

