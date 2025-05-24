#include "Variable.h"
#include <iostream>

int main() {
    Variable a("count", 42);
    Variable b("count", 42);
    Variable c("total", 99);

    std::cout << "a == b? " << (a == b ? "Yes" : "No") << "\n";
    std::cout << "a != c? " << (a != c ? "Yes" : "No") << "\n";

    std::cout << "*a = " << *a << "\n";

    c = a; 
    std::cout << "c after c = a: " << (c == a ? "Equal" : "Not equal") << "\n";
    std::cout << "c name is still: " << c.getName() << "\n";

    return 0;
}
