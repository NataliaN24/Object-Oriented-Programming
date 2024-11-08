#include "NumberSeries.h"
#include <iostream>


int transitionFunction(int x) {
    return x + 2; 
}

int main() {

    NumberSeries series(1, transitionFunction);

   
    std::cout << "First few elements of the series:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "a_" << i << " = " << series.getElement(i) << std::endl;
    }

    std::cout << "Does the series contain the number 8? "
        << (series.contains(8) ? "Yes" : "No") << std::endl;
    std::cout << "Does the series contain the number 15? "
        << (series.contains(15) ? "Yes" : "No") << std::endl;

    series.setStartValue(5);
    std::cout << "\nAfter setting a new start value (5):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "a_" << i << " = " << series.getElement(i) << std::endl;
    }

    series.setFunction([](int x) { return x * 2; }); 
    std::cout << "\nAfter setting a new function (multiply by 2):" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "a_" << i << " = " << series.getElement(i) << std::endl;
    }

    return 0;
}