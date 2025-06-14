#include<iostream>
#include"Intersection.hpp"
#include"TinyMultiset.h"

int main() {
    TinyMultiset setA, setB;

    // Add some values to setA
    setA.add(5); // count = 1
    setA.add(5); // count = 2
    setA.add(7); // count = 1
    setA.add(7); // count = 2
    setA.add(7); // count = 3
    setA.add(7); // will not add more than 3

    // Add some values to setB
    setB.add(5); // count = 1
    setB.add(5); // count = 2
    setB.add(5); // count = 3
    setB.add(5); // still max 3
    setB.add(6); // count = 1
    setB.add(7); // count = 1

    // Create intersection object
    Intersection<TinyMultiset> result(setA, setB);

    // Print intersection counts
    for (int i = 0; i <= 7; i++) {
        int count = result(i);
        if (count > 0)
            std::cout << "Value " << i << " appears in both sets " << count << " time(s).\n";
    }

    // Test operator() of setA directly
    std::cout << "\nsetA(5) = " << setA(5) << "\n"; // 2
    std::cout << "setB(5) = " << setB(5) << "\n";   // 3

    // Test remove()
    setA.remove(5);
    std::cout << "After remove, setA(5) = " << setA(5) << "\n"; // should be 1

    // Intersection updates automatically (still points to original setA/setB)
    std::cout << "Updated intersection(5) = " << result(5) << "\n"; // now 1

    return 0;
}
