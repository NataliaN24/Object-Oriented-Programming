#include "ParcelFactory.h"


Parcel* factory(const char* str) {

	if (strcmp(str, "CircleParcel") == 0)
	{
		double radius = 0;
		std::cin >> radius;
		return new CircleParcel(radius);
	}
	else if (strcmp(str, "RectangleParcel") == 0)
	{
		double a, b = 0;
		std::cin >> a >> b;
		return new RectangleParcel(a, b);
	}
	else if (strcmp(str, "TriangleParcel") == 0)
	{
		double a, b, c = 0;
		std::cin >> a >> b >> c;
		return new TriangleParcel(a, b, c);
	}
	else
	{
		return nullptr;
	}
}