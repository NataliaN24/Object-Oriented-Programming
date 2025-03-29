#pragma once
#include"Task.h"

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
