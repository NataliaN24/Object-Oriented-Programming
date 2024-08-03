#include <iostream>
#include<fstream>

void selfPrinting(std::ifstream& ifs)
{
	char buffer[1024];
	
	while (!ifs.eof())
	{
		ifs.getline(buffer, 1024);
		std::cout << buffer << std::endl;
	}
}

int main()
{
	std::ifstream ifs("Source.cpp");
	if (!ifs.is_open())
	{
		return 0;
	}
	selfPrinting(ifs);
}