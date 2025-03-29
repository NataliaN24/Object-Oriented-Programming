#include <iostream>
#include "Task.h"
#include "MonthlyPlanner.h"

int main() {
    // Create a MonthlyPlanner object
    MonthlyPlanner planner;

    // Add tasks to specific days
    planner.addTask(1, "Task 1", 3,9);  // Day 1, 9:00 AM, priority 3, 60 minutes
    planner.addTask(1, "Task 2",2, 11 ); // Day 1, 11:00 AM, priority 2, 90 minutes
    planner.addTask(2, "Task 3", 1,14); // Day 2, 2:00 PM, priority 1, 30 minutes
    planner.addTask(3, "Task 4", 5,10); // Day 3, 10:00 AM, priority 5, 120 minutes

    // Print out tasks for Day 1 before marking any task as completed
    std::cout << "Tasks on Day 1 before modification:\n";
    planner.printTasksForDay(1);


    // Mark the task for Day 1 at 9:00 AM as completed
    planner.markAsCompleted(1, 9);

    // Print out tasks for Day 1 after marking one task as completed
    std::cout << "\nTasks on Day 1 after modification:\n";
    planner.printTasksForDay(1);

    // Print out tasks for Day 2
    std::cout << "\nTasks on Day 2:\n";
    planner.printTasksForDay(2);

    // Print out tasks for Day 3
    std::cout << "\nTasks on Day 3:\n";
    planner.printTasksForDay(3);

    return 0;
}
