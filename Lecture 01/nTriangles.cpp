#include<iostream>

namespace Points
{
	struct Point
	{
		int x;
		int y;
	};
	void readPoint(Point& p)
	{
		std::cin >> p.x >> p.y;
	}
	double getDist(const Point& p1, const Point& p2)
	{
		int dx = p1.x - p2.x;
		int dy = p1.y - p2.y;
		return sqrt(dx * dx + dy * dy);
	}
	void printPoint(const Point& p) {
		std::cout << "(" << "p.x" << "," << p.y << ")" << std::endl;
	}
}

namespace  Figures
{
	using namespace Points;
	struct Triangle
	{
		Point p1;
		Point p2;
		Point p3;
	};

	void readTriangle(Triangle& tr)
	{
		readPoint(tr.p1);
		readPoint(tr.p2);
		readPoint(tr.p3);
	}

	double getArea(const Triangle& tr)
	{
		double sideA = getDist(tr.p1,tr.p2);
		double sideB = getDist(tr.p2,tr.p3);
		double sideC= getDist(tr.p1,tr.p3);

		double halfPerimeter = (sideA + sideB + sideC) / 2;

		return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
	}

	void sortTrianglesByArea(Triangle* triangles, size_t N)
	{
		double* areas = new double[N];

		for (size_t i = 0; i < N; i++)
		{
			areas[i] = getArea(triangles[i]);
		}
		for (size_t i = 0; i < N - 1; i++)
		{
			int minIndex = i;
			for (size_t j = i + 1; j < N; j++)
			{
				if (areas[j] < areas[minIndex]) 
				{
					minIndex = j;
				}
			}
			if (minIndex != i) 
			{
				std::swap(triangles[i], triangles[minIndex]);
				std::swap(areas[i], areas[minIndex]);
			}
		}
		delete[]areas;
	}
	void printTriangle(const Triangle& tr)
	{
		printPoint(tr.p1);
		printPoint(tr.p2);
		printPoint(tr.p3);
	}
};

int main()
{
	int N;
	std::cin >> N;
	
	using namespace Figures;

	Triangle* arr = new Triangle[N];

	for (size_t i = 0; i < N; i++)
	{
		readTriangle(arr[i]);
	}

	sortTrianglesByArea(arr, N);

	for (size_t i = 0; i < N; i++)
	{
		printTriangle(arr[i]);
	}
	delete[]arr;
}