#pragma once
#include"Command.h"
#include"Store.h"
#include"Gadget.h"

class BuyProduct:public Command
{
	Store& store;
	const Gadget& gadget;
public:
	BuyProduct(Store& st, const Gadget& g);
	void execute()override;
};

