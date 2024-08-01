#include <iostream>

bool checkLittleEndianness()
{
	union EndiannessChecker {
		uint32_t number = 1;
		unsigned char bytes[4];
	} checker;
	return checker.bytes[0];
}

int main()
{
	std::cout << checkLittleEndianness();
}
