#include "Award.h"

Award::Award():Award(0,0)
{
}

Award::Award(size_t pr, size_t pt):price(pr),points(pt)
{
}

size_t Award::getPrice() const
{
	return price;
}

size_t Award::getPoints() const
{
	return points;
}
