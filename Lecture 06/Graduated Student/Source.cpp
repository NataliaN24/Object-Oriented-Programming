#include"GraduatedStudent.h"
#include<iostream>


int main() {
    const char* name = "John Doe";
    int grades[] = { 90, 85, 78 };
    const char* quote = "Learning.";

    GraduatedStudent student1(name, grades, 3, quote);

    std::cout << "Student 1: " << student1.getName() << ", Quote: " << student1.getQuote() << std::endl;


    return 0;
}
