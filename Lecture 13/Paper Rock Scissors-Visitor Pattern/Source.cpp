#include<iostream>
#include"Factory.h"

int main() {
	std::cout << "Choose first object (1 - Paper, 2 - Stone, 3 - Scissors): ";
	Object* first = factory();
	std::cout << "Choose second object (1 - Paper, 2 - Stone, 3 - Scissors): ";
	Object* second = factory();

	if (first && second) {
		first->fight(second); 
		std::cout << std::endl;
	}
	else {
		std::cout << "Invalid input.\n";
	}

	delete first;
	delete second;

	return 0;
}
