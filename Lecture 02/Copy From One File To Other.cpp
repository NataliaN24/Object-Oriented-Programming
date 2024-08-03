#include <iostream>
#include<fstream>

bool copyFromOneFileToOther(const char* source, const char* dest)
{
	std::ifstream ifs(source);
	if (!ifs.is_open())
	{
		return false;
	}
	std::ofstream ofs(dest);
	if (!ofs.is_open())
	{
		return false;
	}
	while (!ifs.eof())
	{
		char buffer[1024];
		ifs.getline(buffer, 1024);
		ofs << buffer << std::endl;
	}

}

int main()
{
	copyFromOneFileToOther("Source.cpp", "1.txt");
}