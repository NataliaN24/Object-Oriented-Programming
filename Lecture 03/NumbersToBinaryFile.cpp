#include <iostream>
#include <sstream>
#include<fstream>

//Напишете програма, която първо записва в двоичен файл N на брой числа,
//въведени от клавиатурата, а след това отпечатва на екрана всяко трето число от файла, които преди това сте създали и съхранили.

int main() {
	{
		std::ofstream ofs("ifs.bin", std::ios::binary);
		if (!ofs.is_open())
		{
			throw ("Error!");
		}
		int n;
		std::cin >> n;
		ofs.write((const char*)&n, sizeof(n));
		for (int i = 0; i < n; i++)
		{
			int number;
			std::cin >> number;
			ofs.write((const char*)&number, sizeof(number));
		}
		ofs.close();  //1 2 5 6 3 9 8 7 10
	}
	{
		std::ifstream ifs("ifs.bin", std::ios::binary);
		if (!ifs.is_open())
		{
			throw ("Error!");
		}
		ifs.read((char*)&n, sizeof(n));
		for (int i = 0; i < n; i++)
		{
			int number;
			ifs.read((char*)&number, sizeof(number));
			if ((i + 1) % 3 == 0)
			{
				std::cout << number << " ";
			}

		}
		ifs.close();
	}
	return 0;
}
