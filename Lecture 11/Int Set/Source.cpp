#include <iostream>
#include "IntRange.h"
#include "ArraySet.h"

int main() {
    try {
        IntRange range(5, 8);  // числа: 5, 6, 7, 8

        std::cout << "range.get(0): " << range.get(0) << std::endl;
        std::cout << "range.get(3): " << range.get(3) << std::endl;
        std::cout << "range.member(6): " << std::boolalpha << range.member(6) << std::endl;
        std::cout << "range.member(9): " << std::boolalpha << range.member(9) << std::endl;

        ArraySet aset(5);
        aset.insert(6);
        aset.insert(7);
        aset.insert(8);

        std::cout << "aset.member(6): " << std::boolalpha << aset.member(6) << std::endl;
        std::cout << "range.intersects(aset): " << std::boolalpha << range.intersects(aset) << std::endl;
        std::cout << "aset.isSubsetOf(range): " << std::boolalpha << aset.isSubsetOf(range) << std::endl;

        std::cout << "range.get(100): ";
        std::cout << range.get(100) << std::endl; 

    }
    catch (const std::exception& e) {
        std::cerr << "\nException caught: " << e.what() << std::endl;
    }

    return 0;
}
