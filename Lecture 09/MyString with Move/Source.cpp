#include <iostream>
#include "MyString.h"

int main() {
    MyString str1("Hello");
    MyString str2("World");

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    MyString str3 = str1 + str2;
    std::cout << "str1 + str2: " << str3 << std::endl;

    str1 += str2;
    std::cout << "str1 after += str2: " << str1 << std::endl;

    MyString str4;
    std::cout << "Enter a string for str4: ";
    std::cin >> str4;
    std::cout << "str4: " << str4 << std::endl;

    std::cout << "Comparing str1 and str2:" << std::endl;
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 != str2: " << (str1 != str2) << std::endl;
    std::cout << "str1 < str2: " << (str1 < str2) << std::endl;
    std::cout << "str1 <= str2: " << (str1 <= str2) << std::endl;
    std::cout << "str1 > str2: " << (str1 > str2) << std::endl;
    std::cout << "str1 >= str2: " << (str1 >= str2) << std::endl;

    return 0;
}
