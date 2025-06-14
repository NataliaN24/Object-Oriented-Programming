#include <iostream>
#include "Vector2D.h"

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);

    std::cout << "Vector v1: (" << v1.getX() << ", " << v1.getY() << ")\n";
    std::cout << "Vector v2: (" << v2.getX() << ", " << v2.getY() << ")\n";

    // Test addition
    Vector2D sum = v1 + v2;
    std::cout << "Sum (v1 + v2): (" << sum.getX() << ", " << sum.getY() << ")\n";

    // Test scalar multiplication
    Vector2D scaled1 = 2.0 * v1;
    Vector2D scaled2 = v1 * 3.0;
    std::cout << "2.0 * v1: (" << scaled1.getX() << ", " << scaled1.getY() << ")\n";
    std::cout << "v1 * 3.0: (" << scaled2.getX() << ", " << scaled2.getY() << ")\n";

    // Test +=
    v1 += v2;
    std::cout << "v1 after v1 += v2: (" << v1.getX() << ", " << v1.getY() << ")\n";

    // Test dot product (^)
    double dotProduct = v1 ^ v2;
    std::cout << "Dot product (v1 ^ v2): " << dotProduct << "\n";

    // Test equality
    Vector2D copy = v2;
    std::cout << "v2 == copy: " << (v2 == copy ? "true" : "false") << "\n";
    std::cout << "v1 != v2: " << (v1 != v2 ? "true" : "false") << "\n";

    return 0;
}
