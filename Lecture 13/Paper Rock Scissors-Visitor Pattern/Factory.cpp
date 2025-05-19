#include "Factory.h"
#include"Paper.h"
#include"Scissors.h"
#include"Stone.h"


Object* factory() {

	int type;//1 for paper 2 for stone 3 for scissors
	std::cin >> type;

	switch (type)
	{
	case 1:
	{
		return new Paper();
	}
	case 2: {
		return new Stone();
	}
	case 3:
	{
		return new Scissors();
	}
	default:
		return nullptr;
		break;
	}








}