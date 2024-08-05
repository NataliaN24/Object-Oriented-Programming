#include <iostream>
#include "NVector.h"

int main() {
    NVector v1(3);
    NVector v2(3);

    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;

    NVector sum = v1 + v2;
    NVector difference = v1 - v2;
    NVector scaled = v1 * 2;
    size_t dotProduct = v1 % v2;
    bool parallel = v1 || v2;
    bool orthogonal = v1 |= v2;

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Scaled v1: " << scaled << std::endl;
    std::cout << "Dot product: " << dotProduct << std::endl;
    std::cout << "Are v1 and v2 parallel? " << (parallel ? "Yes" : "No") << std::endl;
    std::cout << "Are v1 and v2 orthogonal? " << (orthogonal ? "Yes" : "No") << std::endl;

    return 0;
}
