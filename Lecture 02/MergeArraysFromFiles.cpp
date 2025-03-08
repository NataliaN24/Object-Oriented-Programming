#include <iostream>
#include<cassert>
#include<fstream>

//Напишете функция, която приема имената на два текстови файла, в които са записани цели числа в сортиран вид.
//Числата са разделени с интервал. Запишете в нов файл числата от двата дайла в сортиран вид. Числата отново да са разделени с интервал.

int getCharCount(std::ifstream& ifs, char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0,std::ios::beg);
	if (!ifs.is_open())
	{
		return -1;
	}
	int count = 0;
	while (!ifs.eof()) {
		char current = ifs.get();
		if (ifs.eof())
		{
			break;
		}
		if (current == ch)
		{
			count++;
		}
	}
	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}

int* getArrFromFile(const char* filename, size_t& size)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		return 0;
	}
	size = getCharCount(ifs, ' ') + 1;
	int* result = new int[size];

	for (int i = 0; i < size; i++)
	{
		ifs >> result[i];
	}
	ifs.close();
	return result;
}

int* merge(const int* first, size_t size1, const int* sec, size_t size2)
{
	size_t firstIter = 0;
	size_t secIter = 0;
	int* merged = new int[size1 + size2];
	size_t mergedIter = 0;
	while (firstIter < size1 && secIter < size2)
	{
		if (first[firstIter] < sec[secIter])
		{
			merged[mergedIter++] = first[firstIter++];
		}
		else
		{
			merged[mergedIter++] = sec[secIter++];
		}
	}
	while (firstIter < size1)
	{
		merged[mergedIter++] = first[firstIter++];
	}
	while (secIter < size2)
	{
		merged[mergedIter++] = sec[secIter++];
	}
	return merged;
}

void mergeArrayFromFiles(const char* f1, const char* f2, const char* merged)
{
	size_t size1, size2;
	int* firstArray = getArrFromFile(f1, size1);
	if (!firstArray) {
		return;
	}
	int* secArray = getArrFromFile(f2, size2);
	if (!secArray)
	{
		delete[]firstArray;
		return;
	}
	int* result = merge(firstArray, size1, secArray, size2);
	std::ofstream ofs(merged);
	if (!ofs.is_open()) {
		delete[]firstArray;
		delete[]secArray;
		delete[]result;
		return;
	}
	for (int i = 0; i < size1 + size2; ++i)
	{
		ofs << result[i] << " ";

	}
	delete[]firstArray;
	delete[]secArray;
	delete[]result;

	ofs.close();

}

int main()
{
	mergeArrayFromFiles("file1.txt", "file2.txt", "merged.txt");
}
