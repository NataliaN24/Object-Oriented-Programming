#include <iostream>
#include <fstream>

void replace(char ch1, char ch2, std::fstream& file)
{
	while (!file.eof())
	{
		char current = file.get();

		if (current != ch1)
		{
			continue;
		}
		file.seekp(-1, std::ios::cur);
		file.put(ch2);
		file.flush();
	}
}

int main()
{
	std::fstream file("treasureTrail.txt", std::ios::in |std:: ios::out);


	if (!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}

	replace('a', 'X', file);
	return 0;
}