#include <iostream>
#include <fstream>
#include "Polynom.h"

int main() {

  
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Не може да се отвори poly.txt" << std::endl;
        return 1;
    }
 
    Polynom p1;
    p1.load(file);
    std::cout << "Polynom :\n";
    p1.print();

    Polynom p2(2);
    std::cout << "\n\n Second Polynom:\n";
    p2.print();

    p1.add(p2);
    std::cout << "\n\n Sum::\n";
    p1.print();

}
