#include <iostream>
#include "ImmutableString.h"

int main() {
    ImmutableString str1("Hello, World!");
    ImmutableString str2("Another String");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    std::cout << "Length of str1: " << str1.getLength() << std::endl;
    std::cout << "Length of str2: " << str2.getLength() << std::endl;

    std::cout << "str1[0]: " << str1[0] << std::endl;
    std::cout << "str2[1]: " << str2[1] << std::endl;

    if (str1 < str2) {
        std::cout << "str1 is less than str2" << std::endl;
    }
    else if (str1 > str2) {
        std::cout << "str1 is greater than str2" << std::endl;
    }
    else {
        std::cout << "str1 is equal to str2" << std::endl;
    }

    ImmutableString str3 = str1;
    std::cout << "str3 (copy of str1): " << str3 << std::endl;

   

    return 0;
}
