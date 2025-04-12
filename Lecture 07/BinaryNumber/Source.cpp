#include <iostream>
#include "BinaryNumber.h"

int main() {
    // Create two BinaryNumber objects
    BinaryNumber bin1("10010100"); // 148 in decimal
    BinaryNumber bin2("1010000");  // 80 in decimal

    // Testing the "+" (addition) operator
    BinaryNumber sum = bin1 + bin2;
    std::cout << "bin1 + bin2 = " << sum << std::endl;  // Expected: 11100100 (228 in decimal)

    // Testing the "&" (bitwise AND) operator
    BinaryNumber andResult = bin1 & bin2;
    std::cout << "bin1 & bin2 = " << andResult << std::endl;  // Expected: 1000000 (64 in decimal)

    // Testing the "|" (bitwise OR) operator
    BinaryNumber orResult = bin1 | bin2;
    std::cout << "bin1 | bin2 = " << orResult << std::endl;  // Expected: 10110100 (180 in decimal)

    // Testing the "^" (bitwise XOR) operator
    BinaryNumber xorResult = bin1 ^ bin2;
    std::cout << "bin1 ^ bin2 = " << xorResult << std::endl;  // Expected: 11010100 (212 in decimal)

    // Testing the "<<" (left shift) operator
    BinaryNumber leftShiftResult = bin1 << 3; // Shift left by 3 positions
    std::cout << "bin1 << 3 = " << leftShiftResult << std::endl;  // Expected: 10100000 (160 in decimal)

    // Testing the ">>" (right shift) operator
    BinaryNumber rightShiftResult = bin1 >> 3; // Shift right by 3 positions
    std::cout << "bin1 >> 3 = " << rightShiftResult << std::endl;  // Expected: 10010 (18 in decimal)

    return 0;
}
