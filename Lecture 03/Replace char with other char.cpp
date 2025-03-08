#include <iostream>
#include <fstream>

//Solution 1
//Да се напише функция, която заменя всяко срещане на символ във файл с друг символ. Съдържанието на файла не трябва да се зарежда в паметта.

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
//Solution 2

void replace(std::fstream& file, char a, char b)
{
	char current;
	while (file.get(current))
	{
		if (current == a)  
		{
			file.seekp(-1, std::ios::cur);
			file.put(b);
			file.flush();
		}
		if (current == file.eof())
		{
			break;
		}
	}
}

//

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
