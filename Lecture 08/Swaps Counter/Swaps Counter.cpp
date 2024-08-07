#include <iostream>

struct SwapCounter
{
private:
	static int count;
public:
	static void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
		count++;
	}
	static int getCount()
	{
		return count;
	}
	static void resetCount()
	{
		count = 0;
	}

};
int SwapCounter::count = 0;

void print(const int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void bubbleSort(int* arr, size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		bool isSwapped = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				SwapCounter::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped)
			return;
	}
}

void selectionSort(int* arr, size_t size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minElIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minElIndex])
				minElIndex = j;
		}

		if (minElIndex != i)
			SwapCounter::swap(arr[minElIndex], arr[i]);
	}
}


int main()
	{
		SwapCounter::resetCount();
		int array1[5] = { 5, 3, 4, 1, 2 };
		int array2[5] = { 5, 3, 4, 1, 2 };
		bubbleSort(array1, 5);
		std::cout << "Bubble sort swaps: " << SwapCounter::getCount() << std::endl;
		SwapCounter::resetCount();
		selectionSort(array2, 5);
		std::cout << "Selection sort swaps: " << SwapCounter::getCount() << std::endl;
		return 0;
	}
