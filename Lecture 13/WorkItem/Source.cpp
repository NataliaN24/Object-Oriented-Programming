#include <iostream>
#include <chrono>
#include "TaskGroup.h"
#include "SingleTask.h"

int main() {
    using namespace std::chrono;

    // Get current UNIX time in milliseconds
    long now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    // Create individual tasks
    SingleTask t1("Read Book", now - 5000, 3000);  // done
    SingleTask t2("Write Code", now, 10000);       // not yet done

    // Create a task group
    TaskGroup group("Daily Tasks");
    group.addTask(t1);
    group.addTask(t2);

    // Print group info
    std::cout << "Status at now = " << now << ":\n";
    group.print();

    // Check if group is done
    std::cout << "\nGroup completed: " << std::boolalpha << group.status(now) << "\n";

    // Create another group that wraps the first one
    TaskGroup bigGroup("Weekly Tasks");
    bigGroup.addTask(group);

    std::cout << "\nNested Group:\n";
    bigGroup.print();

    return 0;
}
