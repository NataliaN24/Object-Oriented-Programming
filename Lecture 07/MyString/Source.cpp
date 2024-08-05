#include <iostream>
#include "MyString.h"

int main() {
    MyString str1("Hello");
    MyString str2("World");
    MyString str3 = str1 + " " + str2;

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    str1 += " Everyone";
    std::cout << "After appending to str1: " << str1 << std::endl;

    std::cout << "Comparison (str1 == str2): " << (str1 == str2) << std::endl;
    std::cout << "Comparison (str1 != str2): " << (str1 != str2) << std::endl;
    std::cout << "Comparison (str1 < str2): " << (str1 < str2) << std::endl;

    return 0;
}
