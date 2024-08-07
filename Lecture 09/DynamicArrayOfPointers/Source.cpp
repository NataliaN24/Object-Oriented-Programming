#include <iostream>
#include "DynamicArrayOfPointers.h"

int main() {
    DynamicArrayOfPointers arr;

    arr.addAtFirstFreeIndex(A{ 1, 2 });
    arr.addAtFirstFreeIndex(A{ 3, 4 });
    arr.addAtFirstFreeIndex(A{ 5, 6 });

    std::cout << "Array elements:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr.containsAt(i)) {
            std::cout << "Element " << i << ": x = " << arr[i].x << ", y = " << arr[i].y << std::endl;
        }
    }

    arr.popBack();
    std::cout << "After popBack, array elements:" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr.containsAt(i)) {
            std::cout << "Element " << i << ": x = " << arr[i].x << ", y = " << arr[i].y << std::endl;
        }
    }

    arr.setAtIndex(A{ 7, 8 }, 0);
    std::cout << "After setAtIndex, element 0: x = " << arr[0].x << ", y = " << arr[0].y << std::endl;

    DynamicArrayOfPointers arrCopy = arr;
    std::cout << "Copied array elements:" << std::endl;
    for (size_t i = 0; i < arrCopy.size(); ++i) {
        if (arrCopy.containsAt(i)) {
            std::cout << "Element " << i << ": x = " << arrCopy[i].x << ", y = " << arrCopy[i].y << std::endl;
        }
    }

    DynamicArrayOfPointers arrMove = std::move(arr);
    std::cout << "Moved array elements:" << std::endl;
    for (size_t i = 0; i < arrMove.size(); ++i) {
        if (arrMove.containsAt(i)) {
            std::cout << "Element " << i << ": x = " << arrMove[i].x << ", y = " << arrMove[i].y << std::endl;
        }
    }

    return 0;
}
