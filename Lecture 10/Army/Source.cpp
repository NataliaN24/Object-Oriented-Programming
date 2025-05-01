#include <iostream>
#include "Soldier.h"
#include "Commander.h"
#include "General.h"

int main() {
    Soldier s1("Ivan", 25, 80, 1000);
    Soldier s2("Petar", 28, 90, 1100);
    Soldier s3("Stoyan", 30, 85, 1050);
    Soldier s4("Georgi", 27, 88, 1150);

    std::cout << "Soldiers:\n";
    s1.print();
    s2.print();
    s3.print();
    s4.print();

    Soldier battalion1[] = { s1, s2 };
    Soldier battalion2[] = { s3, s4 };

    Commander c1("Commander One", 45, 130, 2500, 2, battalion1);
    Commander c2("Commander Two", 43, 120, 2400, 2, battalion2);

    std::cout << "\nCommanders:\n";
    c1.print();
    c2.print();

    Commander commanderList[] = { c1, c2 };

    General g("General Vasilev", 60, 160, 4000, "Eastern Front", commanderList, 2);

    std::cout << "\nGeneral:\n";
    g.print();

    std::cout << "\nArmy Summary:\n";
    g.printArmy(std::cout);

    return 0;
}
