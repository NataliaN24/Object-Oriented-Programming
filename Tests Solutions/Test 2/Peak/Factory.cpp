#include "Factory.h"


Peak* peak(PeakType type)
{
	switch (type) {
	case PeakType::Tpeak:
	{
		return new TPeak();
	}
	case PeakType::MPeak:
	{
		return new MPeak();
	}
	return nullptr;

	}
}