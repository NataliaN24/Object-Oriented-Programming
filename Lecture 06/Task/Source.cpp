#include <iostream>
#include "Task.h"

int main() {
    // Create a task with a description, priority, and time
    Task t1("Initial Task", 3, 60);

    // Print out the initial description and status
    std::cout << "Task 1 Description: " << t1.getDescr() << "\n";
    std::cout << "Task 1 Status: " << (t1.getStatus() ? "Done" : "Not Done") << "\n";

    // Change the task status to done
    t1.changeSatusToDone();

    // Print the status after modification
    std::cout << "Task 1 Status after modification: " << (t1.getStatus() ? "Done" : "Not Done") << "\n";

    // Test the comparison between two tasks
    Task t2("Another Task", 2, 120);

    const Task& higherPriorityTask = t1.compare(t2);
    std::cout << "Task with higher priority: " << higherPriorityTask.getDescr() << "\n";
    return 0;
}
