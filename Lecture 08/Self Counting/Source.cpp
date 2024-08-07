#include "SelfCounting.h"
#include <iostream>

int main()
{
    std::cout << SelfCounting::getLiveObjCout() << std::endl;
    std::cout << SelfCounting::getCreatedCount() << std::endl;

    SelfCounting obj1;
    std::cout << SelfCounting::getLiveObjCout() << std::endl;
    std::cout << SelfCounting::getCreatedCount() << std::endl;

    {
        SelfCounting obj2;
        std::cout << SelfCounting::getLiveObjCout() << std::endl;
        std::cout << SelfCounting::getCreatedCount() << std::endl;
    }

    std::cout << SelfCounting::getLiveObjCout() << std::endl;
    std::cout << SelfCounting::getCreatedCount() << std::endl;

    return 0;
}
