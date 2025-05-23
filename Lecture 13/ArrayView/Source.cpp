#include <iostream>
#include <stdexcept>
#include <cstring>
#include"ArrayView.hpp"



int main() {
    try {
        int numbers[] = { 10, 20, 30, 40, 50 };
        size_t size = sizeof(numbers) / sizeof(numbers[0]);

        ArrayView<int> view(numbers, size);
        std::cout << "Original view: " << view << std::endl;

        ArrayView<int> sub = view.subArr(2);  
        std::cout << "Subview from index 2: " << sub << std::endl;

        std::cout << "Element at index 1 of subview: " << sub[1] << std::endl;

        std::cout << "Is subview empty? " << (sub.isEmpty() ? "Yes" : "No") << std::endl;

        std::cout << "Number of elements in subview: " << sub.getNumberOfElements() << std::endl;

        ArrayView<int> invalid = view.subArr(6); 
        std::cout << "This won't be printed: " << invalid << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
