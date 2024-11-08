#include "FilteredStudentDB.h"
#include "SortedStudentDB.h"
#include <iostream>

bool courseFilter(const Student& student) {
    return student.getCourse() == 2;
}



int main() {
    SortedStudentDB sortedDb;
    sortedDb.add(Student(MyString("Alice"), 1234, 2));
    sortedDb.add(Student(MyString("Bob"), 5678, 3));
    sortedDb.add(Student(MyString("Carol"), 9101, 2));
    sortedDb.add(Student(MyString("Dave"), 1121, 1));

    std::cout << "Original database:" << std::endl;
    sortedDb.display();

    std::cout << "Sorted by name:" << std::endl;
    sortedDb.sortBy(compareByName);
    sortedDb.display();

    std::cout << "Sorted by faculty number:" << std::endl;
    sortedDb.sortBy(compareByFn);
    sortedDb.display();

    std::cout << "Sorted by course:" << std::endl;
    sortedDb.sortBy(compareByCourse);
    sortedDb.display();

    FilteredStudentDB filteredDb;
    filteredDb.add(Student(MyString("Alice"), 1234, 2));
    filteredDb.add(Student(MyString("Bob"), 5678, 3));
    filteredDb.add(Student(MyString("Carol"), 9101, 2));
    filteredDb.add(Student(MyString("Dave"), 1121, 1));

    std::cout << "Filtered students by course == 2:" << std::endl;
    filteredDb.filter(courseFilter);
    filteredDb.display();

    std::cout << "Limited to the first 1 student after filtering:" << std::endl;
    filteredDb.limit(1);
    filteredDb.display();

    return 0;
}
