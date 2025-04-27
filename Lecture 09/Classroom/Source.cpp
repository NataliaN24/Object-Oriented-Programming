#include <iostream>
#include "Student.h"
#include "Classroom.h"

int main()
{
    Classroom classroom(10);

    Student s1("Alice", 1001);
    Student s2("Bob", 1002);
    Student s3("Charlie", 1003);
    Student s4("Diana", 1004);

    if (classroom.howManyFreeSeats() > 0 && classroom.getCapacity() > 0)
    {
        if (classroom.getCount() < classroom.getCapacity())
        {
            classroom.addStudent(0, s1);
            std::cout << "Added Alice at position 0." << std::endl;
        }
    }

    if (classroom.getCount() < classroom.getCapacity())
    {
        classroom.addStudent(3, s2);
        std::cout << "Added Bob at position 3." << std::endl;
    }

    if (classroom.getCount() < classroom.getCapacity())
    {
        classroom.addStudent(5, s3);
        std::cout << "Added Charlie at position 5." << std::endl;
    }

    if (classroom.getCount() < classroom.getCapacity())
    {
        classroom.addStudent(7, std::move(s4));
        std::cout << "Added Diana at position 7." << std::endl;
    }

    std::cout << "\nCurrent classroom:" << std::endl;
    classroom.print();
    std::cout << "\nFree seats: " << classroom.howManyFreeSeats() << std::endl;

    if (classroom.getCapacity() > 3 && classroom.getCapacity() > 0 &&
        classroom.getCount() > 1 &&
        classroom.getCapacity() > 3 && classroom.getCapacity() > 0)
    {
        std::cout << "\nSwapping students at 0 and 3..." << std::endl;
        classroom.swapStudents(0, 3);
        classroom.print();
    }

    if (classroom.getCapacity() > 5 && classroom.getCapacity() > 0)
    {
        std::cout << "\nDropping student at index 5..." << std::endl;
        classroom.dropStudent(5);
        classroom.print();
        std::cout << "\nFree seats after drop: " << classroom.howManyFreeSeats() << std::endl;
    }

    std::cout << "\nFinding emptiest row (rowSize = 2, rowCount = 5): " << std::endl;
    int emptiestRow = classroom.getEmptiestRow(2, 5);
    std::cout << "Emptiest row is: " << emptiestRow << std::endl;

    return 0;
}
