#include "BuyProduct.h"

BuyProduct::BuyProduct(Store& st, const Gadget& g):store(st),gadget(g)
{
}

void BuyProduct::execute()
{
	store.buyProduct(gadget);
}
