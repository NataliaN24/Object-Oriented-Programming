#include "DynamicBitset.h"
#include<iostream>

int main() {
    DynamicBitset set1(20);
    DynamicBitset set2(20);

    set1.add(3);
    set1.add(5);
    set1.add(10);

    set2.add(5);
    set2.add(8);
    set2.add(10);

    DynamicBitset unionSet = unionOfSets(set1, set2);
    DynamicBitset intersectionSet = intersectionOfSets(set1, set2);

    std::cout << "Set 1: ";
    set1.print();

    std::cout << "Set 2: ";
    set2.print();

    std::cout << "Union: ";
    unionSet.print();

    std::cout << "Intersection: ";
    intersectionSet.print();

    return 0;
}
