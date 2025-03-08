#include <iostream>
#include <sstream>

//Напишете програма, която чете ред с числа(разделени с интервали) от стандартния вход 
//и използва std::stringstream, за да ги обработи.Програмата трябва да намери :
//
//Сумата на числата
//Средното аритметично
//Най - голямото и най - малкото число

int main() {
	std::stringstream ss;
	int number;
	int sum = 0;
	int count = 0;
	int maxNum = -2147483648;
	int minNum = 2147483647;

	while (std::cin >> number)
	{
		ss << number << " "; //ENTER EOF TO STOP ENTERING NUMBERS
	}
	ss.seekg(0, std::ios::beg);
	while (ss >> number)
	{
		sum += number;
		count++;
		if (number < minNum)
		{
			minNum = number;
		}
		if (number > maxNum)
		{
			maxNum = number;
		}
	}

	if (count > 0)
	{
		double average = (double)sum / count;
		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Average: " << average << std::endl;
		std::cout << "Max: " << maxNum << std::endl;
		std::cout << "Min: " << minNum << std::endl;
	}
	else {
		std::cout << "No numbers entered." << std::endl;
	}

}
