#include <iostream>
#include "Path.h" 


int main()
{
    Town town1(1);
    Town town2(2);
    Town town3(3);
    Town town4(4);
    Town town5(5);

    Path path1;
    path1.addTown(town1);
    path1.addTown(town3);
    path1.addTown(town5);

    std::cout << "Path1 after adding towns: ";
    path1.print();
    std::cout << std::endl;

    path1.removeTown(town3);

    std::cout << "Path1 after removing town 3: ";
    path1.print();
    std::cout << std::endl;

    Path path2;
    path2.addTown(town5);
    path2.addTown(town3);
    path2.addTown(town4);

    std::cout << "Path2 after adding towns: ";
    path2.print();
    std::cout << std::endl;

    Path unionPath = path1.unionPaths(path2);
    std::cout << "Union of Path1 and Path2: ";
    unionPath.print();
    std::cout << std::endl;

    Path intersectionPath = path1.intersectionPaths(path2);
    std::cout << "Intersection of Path1 and Path2: ";
    intersectionPath.print();
    std::cout << std::endl;

    return 0;
}
