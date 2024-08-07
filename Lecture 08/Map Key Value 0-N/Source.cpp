#include"MapKey0toN.h"
#include<iostream>

int main()
{
    MapKey0toN map(0);
    map.add(1, 100);
    map.add(2, 200);
    map.add(3, 300);

    std::cout << map.contains(1) << std::endl;
    std::cout << map.contains(4) << std::endl;
    std::cout << map.getValue(2) << std::endl;

    try {
        std::cout << map.getValue(4) << std::endl;
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}
