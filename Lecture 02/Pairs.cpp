#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>
#include<cassert>
#include <fstream>
constexpr char filename[] = "result.txt";
//Да се създаде структура Pair, която представя наредена двойка от естествени числа.
//Да се създаде структура, която представя Relation.В релацията има най - много 25 наредени двойки и структурата пази текущия си размер.
//Да се създаде функция writeRelationToFile, която записва релацията в даден файл;
//Да се създаде функция readRelationFromFile, която прочита релация от даден файл;
//Да се напише функция addPairToRelation, която добавя наредена двойка към релацията;
//Hint: Следните функции може да са ви полезни : readPairFromFile и writePairToFile

struct Pair
{
	int a;
	int b;
};

void writePairToFile(std::ofstream &ofs ,const Pair& p)
{
	ofs << "<" << p.a << "," << p.b << ">\n";
}
void  readPairFromFile(std::ifstream&ifs,Pair& p)
{
	char ch;
	ifs >> ch >> p.a >> ch >> p.b >> ch;
}


struct Relation
{
	Pair pairs[25];
	size_t count;
};

void writeRelationToFile(const Relation& r)
{
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		throw ("Error!");
	}
	ofs << r.count<<"\n";
	for(size_t i=0;i<r.count;i++)
	{
		writePairToFile(ofs,r.pairs[i]);
	}
}
void readRelationFromFile(Relation& r)
{
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		throw ("Error!");
	}
	ifs >> r.count;
	for (size_t i = 0; i < r.count; i++)
	{
		readPairFromFile(ifs,r.pairs[i]);
	}
}

int main() {
	Relation r = { {{1, 2}, {3, 4}, {5, 6}}, 3 };
	writeRelationToFile(r);

	Relation r2;
	readRelationFromFile(r2);

	for (size_t i = 0; i < r2.count; i++)
	{
		std::cout << "(" << r2.pairs[i].a << ", " << r2.pairs[i].b << ")\n";
	}

	return 0;

}
