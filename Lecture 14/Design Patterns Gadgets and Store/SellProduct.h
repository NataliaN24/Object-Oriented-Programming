#pragma once
#include"Command.h"
#include"Store.h"
#include"Gadget.h"

class SellProduct:public Command
{
	Store& store;
	const Gadget& gadget;
public:
	SellProduct(Store& store, const Gadget& gadget);
	void execute()override;
};

