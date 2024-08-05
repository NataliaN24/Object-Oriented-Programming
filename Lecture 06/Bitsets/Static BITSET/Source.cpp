#include"Bitset.h"

int main() {
    Bitset set1, set2;

    set1.addNumber(3);
    set1.addNumber(5);
    set1.addNumber(10);

    set2.addNumber(5);
    set2.addNumber(8);
    set2.addNumber(10);

    Bitset unionSet = set1.unionOfSets(set2);
    Bitset intersectionSet = set1.interesectionOfSets(set2);

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
