#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool(*incl)(unsigned n)):DynamicSet(n)
{
	fill(incl);
}

void SetByCriteria::setInclude(bool(*incl)(unsigned n))
{
	fill(incl);
}

void SetByCriteria::fill(bool(*pred)(unsigned n))
{
	for (unsigned i = 0; i < getN(); ++i)
	{
		if (pred(i))
		{
			add(i);
		}
		else
		{
			remove(i);
		}
	}
}