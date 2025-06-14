#include <iostream>
#include <fstream>
#include "Statistics.h"

int main() {
    std::ifstream file1("file1.txt");//1.5 2.0 3.5 4.0
    std::ifstream file2("file2.txt"); //2.5 1.0 1.5

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Cannot open one of the files.\n";
        return 1;
    }

    Statistics s1, s2;

    s1.load(file1);
    s2.load(file2);

    std::cout << "First array:\n";
    s1.print();

    std::cout << "\nSecond array:\n";
    s2.print();

    Statistics combined = s1;
    combined.combine(s2);

    std::cout << "\nCombined:\n";
    combined.print();

    std::cout << "\nMinimum: " << combined.min() << "\n";
    std::cout << "Average: " << combined.printAvg() << "\n";

    return 0;
}
