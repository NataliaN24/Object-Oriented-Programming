#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<cassert>
#include <fstream>
constexpr char filename[] = "numbers.txt";
constexpr int maxlen = 64;
//Напишете програма, която прочита от текстов файл дължината на списък 
//от числа и после самите числа(до 64 броя), и извежда на екрана най - често срещаното число.

int readFromFile(std::ifstream& ifs)
{
	size_t length;
	ifs >> length;
	if (length > maxlen) {
		std::cerr << "Error: The number of elements exceeds the maximum allowed (64)." << std::endl;
		return -1;
	}
	int numbers[maxlen];
	for (int i = 0; i < length; i++)
	{
		ifs >> numbers[i];
	}
	int mostFrequentNumber = numbers[0];
	int maxCount = 1;
	for (int i = 0; i < length; i++)
	{
		int count = 0;
		for (int j = 0; j < length; j++)
		{
			if (numbers[i] == numbers[j])
			{
				count++;
			}

		}
		if (maxCount < count)
		{
			maxCount = count;
			mostFrequentNumber = numbers[i];
		}
	}
	return mostFrequentNumber;
}

int main()
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		throw ("Error!");
	}
	int result = readFromFile(ifs);
	if (result != -1) {
		std::cout << "The most frequent number is: " << result << std::endl;
	}

	ifs.close();  
	return 0;

}
