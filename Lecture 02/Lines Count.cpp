#include <iostream>
#include<fstream>

const char NEW_LINE = '\n';
int getCharCount(std::ifstream& ifs, char ch)
{
	if (!ifs.is_open())
	{
		return -1;
	}
	int count = 0;
	while (!ifs.eof()) {
		char current = ifs.get();
		if (ifs.eof())
		{
			return count;
		}
		if (current == ch)
		{
			count++;
		}
	}
	return 0;

}
int getLinesCount(const char* filename)
{
	if(!filename)
	{
		return -1;
	}
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		return 0;
	}
	return getCharCount(ifs, NEW_LINE);
}
int main()
{
	std::cout << getLinesCount("Source.cpp");
}

//second solution
constexpr char symbol = '\n';

int count(std::ifstream&ifs) {
	int rows = 0;
	while (!ifs.eof())
	{
		if (ifs.get() == symbol)
		{
			rows++;
		}
	}
	return rows+1;
	
}


int main() {

	std::ifstream ifs("Source.cpp");
	std::cout << count(ifs);

}
