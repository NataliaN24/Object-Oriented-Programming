#include <iostream>
#include "Multiset.h"

int main() {
    // Create a multiset that can hold numbers from 0 to 15 (16 elements)
    Multiset mySet(16);

    // Add numbers to the multiset
    mySet.addNumber(3);
    mySet.addNumber(3);
    mySet.addNumber(5);
    mySet.addNumber(7);
    mySet.addNumber(7);
    mySet.addNumber(7);

    // Print the current state of the multiset
    std::cout << "Current multiset: ";
    mySet.printSets(); // Expected output: {3 3 5 7 7 7}

    // Remove a number
    mySet.removeNumber(7);
    std::cout << "\nAfter removing one occurrence of 7: ";
    mySet.printSets(); // Expected output: {3 3 5 7 7}

    // Remove another occurrence
    mySet.removeNumber(7);
    std::cout << "\nAfter removing another occurrence of 7: ";
    mySet.printSets(); // Expected output: {3 3 5 7}

    // Remove the last occurrence
    mySet.removeNumber(7);
    std::cout << "\nAfter removing the last occurrence of 7: ";
    mySet.printSets(); // Expected output: {3 3 5}

    // Try to remove 5 and see the result
    mySet.removeNumber(5);
    std::cout << "\nAfter removing the occurrence of 5: ";
    mySet.printSets(); // Expected output: {3 3}

    // Remove all occurrences of 3
    mySet.removeNumber(3);
    mySet.removeNumber(3);
    std::cout << "\nAfter removing both occurrences of 3: ";
    mySet.printSets(); // Expected output: {}

    return 0;
}
