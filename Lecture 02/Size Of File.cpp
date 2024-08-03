#include <iostream>
#include<fstream>

size_t getFileSize(std::ifstream& ifs)
{
	size_t current = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(current, std::ios::beg);
	return size;
}

int main()
{
	std::ifstream ifs("text.txt");
	if (!ifs.is_open())
	{
		return 0;
	}
	std::cout << getFileSize(ifs);
}