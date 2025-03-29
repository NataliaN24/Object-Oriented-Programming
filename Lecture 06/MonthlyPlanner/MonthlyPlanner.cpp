#include "MonthlyPlanner.h"

bool MonthlyPlanner::isValidDayAndTask(int day, int taskNumber)
{
	return day >= 1 && day <= DAYS_IN_MONTH && taskNumber >= 1 && taskNumber <= MAX_TASKS_PER_DAY;
}

MonthlyPlanner::MonthlyPlanner()
{
	for (int i = 0; i < DAYS_IN_MONTH; i++)
	{
		for (int j = 0; j < MAX_TASKS_PER_DAY; j++)
		{
			tasks[i][j] = Task();
		}
	}
}

void MonthlyPlanner::addTask(int day, const char* description, size_t priority, unsigned int hour)
{
	if (day < 1 || day > DAYS_IN_MONTH) {
		std::cout << "Invalid day!" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_TASKS_PER_DAY; i++)
	{
		if (tasks[day - 1][i].getDescr() == nullptr) {
			tasks[day - 1][i] = Task(description, priority, hour);
			std::cout << "Task added for day " << day << " at " << hour << " o'clock." << std::endl;
			return;
		}
	}
	std::cout << "No space for more tasks on day " << day << "!" << std::endl;
}
void MonthlyPlanner::removeTask(int day, int taskNumber)
{
	if (!isValidDayAndTask(day, taskNumber)) {
		std::cout << "Invalid day or task number!" << std::endl;
		return;
	}
	if (tasks[day - 1][taskNumber - 1].getDescr() != nullptr)
	{
		tasks[day - 1][taskNumber - 1] = Task();
	}
	else
	{
		std::cout << "No task to remove on day " << day << ", task " << taskNumber << "." << std::endl;
	}

}

void MonthlyPlanner::displayUnfinishedTasks(int day) const
{
	if (day > DAYS_IN_MONTH ||day<1)
	{
		return;
	}
	bool found = false;
	std::cout << "Unfinished tasks for day " << day << ":" << std::endl;
	for (int i = 0; i < MAX_TASKS_PER_DAY; i++)
	{
		if (tasks[day - 1][i].getDescr() != nullptr && !tasks[day - 1][i].getStatus()) {
			std::cout << "Task " << i + 1 << ": " << tasks[day - 1][i].getDescr() << " at " << tasks[day - 1][i].getMinutes()/60 << " o'clock." << std::endl;
			found = true;
		}
	}
	if (!found) {
		std::cout << "No unfinished tasks for day " << day << "." << std::endl;
	}
}

void MonthlyPlanner::markAsCompleted(int day, int taskNumber)
{
	if (!isValidDayAndTask(day, taskNumber)) {
		std::cout << "Invalid day or task number!" << std::endl;
		return;
	}
	if (tasks[day - 1][taskNumber - 1].getDescr() != nullptr) {
		tasks[day - 1][taskNumber - 1].changeSatusToDone();  // Mark the task as done
		std::cout << "Task " << taskNumber << " on day " << day << " marked as completed." << std::endl;
	}
	else {
		std::cout << "No task found to mark as completed on day " << day << ", task " << taskNumber << "." << std::endl;
	}
}

void MonthlyPlanner::saveToFile(const char* filename)
{
	std::ofstream ofs(filename);
	if (!ofs) {
		std::cout << "Error opening file for writing!" << std::endl;
		return;
	}

	for (int i = 0; i < DAYS_IN_MONTH; ++i) {
		for (int j = 0; j < MAX_TASKS_PER_DAY; ++j) {
			if (tasks[i][j].getDescr() != nullptr) {
				ofs << (i + 1) << " "
					<< tasks[i][j].getMinutes()/60 << " "
					<< tasks[i][j].getDescr() << " "
					<< tasks[i][j].getPriority() << " "
					<< tasks[i][j].getMinutes() << " "
					<< tasks[i][j].getStatus() << "\n";
			}
		}
	}
	ofs.close();
	std::cout << "Planner data saved to " << filename << std::endl;
}

void MonthlyPlanner::loadFromFile(const char* filename)
{
	std::ifstream ifs(filename);
	if (!ifs) {
		std::cout << "Error opening file for reading!" << std::endl;
		return;
	}

	int day, priority, hour;
	char buffer[1024];
	bool completed;

	while (ifs >> day >> hour >> buffer >> priority >>  completed) {
		if (day < 1 || day > DAYS_IN_MONTH) continue;

		if (buffer[0] == '\0') continue;

		addTask(day, buffer,  priority, hour);

		if (completed) {
			markAsCompleted(day, MAX_TASKS_PER_DAY);
		}
	}

	ifs.close();
	std::cout << "Planner data loaded from " << filename << std::endl;
}

void MonthlyPlanner::printTasksForDay(int day)
{
	if (day < 1 || day > DAYS_IN_MONTH) {
		std::cout << "Invalid day!" << std::endl;
		return;
	}

	std::cout << "Tasks for day " << day << ":\n";
	bool hasTasks = false;

	for (int i = 0; i < MAX_TASKS_PER_DAY; ++i) {
		if (tasks[day - 1][i].getDescr() != nullptr) {
			hasTasks = true;
			std::cout << "Task " << (i + 1) << ": "
				<< tasks[day - 1][i].getDescr() << ", "
				<< "Priority: " << tasks[day - 1][i].getPriority() << ", "
				<< "Duration: " << tasks[day - 1][i].getMinutes() << " mins, "
				<< (tasks[day - 1][i].getStatus() ? "Completed" : "Not completed") << std::endl;
		}
	}

	if (!hasTasks) {
		std::cout << "No tasks for this day." << std::endl;
	}
}
