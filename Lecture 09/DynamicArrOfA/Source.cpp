#include <iostream>
#include "DynamicArrayOfA.h"

int main() {
    DynamicArrayOfA arr;

    arr.pushBack(A{ 1, 2 });
    arr.pushBack(A{ 3, 4 });
    arr.pushBack(A{ 5, 6 });

    std::cout << "Array elements:" << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << "Element " << i << ": a = " << arr[i].a << ", b = " << arr[i].b << std::endl;
    }

    std::cout << "Array size: " << arr.getSize() << std::endl;

    arr.popBack();
    std::cout << "After popBack, array size: " << arr.getSize() << std::endl;

    arr.setAtIndex(A{ 7, 8 }, 0);
    std::cout << "After setAtIndex, element 0: a = " << arr[0].a << ", b = " << arr[0].b << std::endl;

    DynamicArrayOfA arrCopy = arr;
    std::cout << "Copied array elements:" << std::endl;
    for (size_t i = 0; i < arrCopy.getSize(); ++i) {
        std::cout << "Element " << i << ": a = " << arrCopy[i].a << ", b = " << arrCopy[i].b << std::endl;
    }

    DynamicArrayOfA arrMove = std::move(arr);
    std::cout << "Moved array elements:" << std::endl;
    for (size_t i = 0; i < arrMove.getSize(); ++i) {
        std::cout << "Element " << i << ": a = " << arrMove[i].a << ", b = " << arrMove[i].b << std::endl;
    }

    return 0;
}