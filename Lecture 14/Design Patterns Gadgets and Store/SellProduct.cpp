#include "SellProduct.h"

SellProduct::SellProduct(Store& store, const Gadget& gadget):store(store),gadget(gadget)
{
}

void SellProduct::execute()
{
	store.sellProduct(gadget);
}
