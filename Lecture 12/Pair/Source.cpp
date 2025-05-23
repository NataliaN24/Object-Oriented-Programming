#include <iostream>
#include <stdexcept>
#include <cstring>
#include"Pair.hpp"

int main() {
    Pair<int, std::string> p1(1, "apple");
    Pair<int, std::string> p2(2, "banana");

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";

    std::cout << "p1 == p2? " << (p1 == p2 ? "Yes" : "No") << "\n";
    std::cout << "p1 < p2? " << (p1 < p2 ? "Yes" : "No") << "\n";

    std::cout << "Enter a pair (int string): ";
    Pair<int, std::string> p3(0, "");
    std::cin >> p3;
    std::cout << "You entered: " << p3 << "\n";

    return 0;
}
