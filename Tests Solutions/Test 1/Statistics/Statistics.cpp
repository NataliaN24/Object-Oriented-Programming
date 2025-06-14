#include"Statistics.h"

void Statistics::copyFrom(const Statistics& other) {
	size = other.size;
	arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}
void Statistics::free() {
	delete[]arr;
	size = 0;
}


Statistics::Statistics() {
	size = 0;
	arr = new double[size];
}
Statistics::Statistics(const double* a, size_t n) {
	size = n;
	arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
}
Statistics::Statistics(const Statistics& other) {

	copyFrom(other);
}
Statistics::~Statistics() {
	free();
}
Statistics& Statistics:: operator=(const Statistics& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
int getCharCount(std::ifstream& ifs)
{
    if (!ifs.is_open())
    {
        throw ("Error opening the file!");
    }
    int count = 0;
    bool end = false;

    while (!ifs.eof())
    {
        char current = ifs.get();
        if (current == INTERVAL)
        {
            count++;
			end = false;
        }
        if (ifs.eof())
        {
			end = true;
        }


    }
    if (end)
    {
        count++;
    }
    ifs.clear();
    ifs.seekg(0);

    return count;

}

void Statistics::load(std::ifstream& ifs) {
	free();
	size = getCharCount(ifs);
	arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		ifs >> arr[i];
	}
}
double Statistics::min()const
{
	double minNumber = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= minNumber)
		{
			minNumber = arr[i];
		}
	}
	return minNumber;

}
double Statistics::printAvg()const 
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

void Statistics::resize(size_t maxCount) {
	double* newArr = new double[maxCount]{ 0 };

	// Copy old values to the end (align powers!)
	int offset = maxCount - size;
	for (int i = 0; i < size; i++)
	{
		newArr[i + offset] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size = maxCount;
}

Statistics& Statistics::combine(const Statistics& other) {
	int maxCount = (this->size > other.size) ? this->size : other.size;

	if (maxCount > size)
	{
		resize(maxCount);
	}
	int offset = maxCount - other.size;
	for (int i = 0; i < other.size; i++)
	{
		arr[i + offset] += other.arr[i];
	}
	return *this;
}

void Statistics::print()const {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}