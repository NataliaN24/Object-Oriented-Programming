#include "SetByCriteria.h"

void SetByCriteria::copyFrom(const  SetByCriteria& other)
{
	predicate = other.predicate;
	size = other.size;
	elements = new int[size];

	for (int i = 0; i < size; i++)
	{
		elements[i] = other.elements[i];
	}
	currentIndex = currentIndex;
}

void SetByCriteria::moveFrom(SetByCriteria&& other)noexcept
{
	predicate = other.predicate;
	size = other.size;
	elements = other.elements;
	currentIndex = other.currentIndex;

	other.elements = nullptr;
	other.predicate = nullptr;
	other.size = 0;
	other.currentIndex = -1;
}

void SetByCriteria::free()
{
	delete[]elements;
	elements = nullptr;
	predicate = nullptr;
	size = 0;
	currentIndex = -1;
}

SetByCriteria::SetByCriteria()
{
	elements = nullptr;
	predicate = nullptr;
	size = 0;
	currentIndex = -1;
}

SetByCriteria::SetByCriteria(const SetByCriteria& other)
{
	copyFrom(other);
}

SetByCriteria::SetByCriteria(SetByCriteria&& other)noexcept
{
	moveFrom(std::move(other));
}

SetByCriteria& SetByCriteria:: operator=(const SetByCriteria& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}

SetByCriteria& SetByCriteria::operator=(SetByCriteria&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return*this;
}

bool SetByCriteria::contains(int element) const  {
	return predicate(element, elements, size);
}

SetByCriteria::SetByCriteria(bool (*pred)(int, const int*, int),  int* elems, int sz): predicate(pred), elements(elems), size(sz) {}

int SetByCriteria::nextElement()
{
	if (currentIndex < size)
	{
		return elements[currentIndex];
	}
	else
	{
		throw std::out_of_range("No more elements in the set");
	}

}

bool isElementInFiniteSet(int element, const int* elements, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		if (element == elements[i])
		{
			return true;
		}
	}
	return false;
}

bool isElementNotDivisible(int element, const int* elements, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (element % elements[i]==0)
		{
			return false;
		}
	}
	return true;
}

bool isElementDivisibleByOne(int element, const int* elements, int size) {
	
	for (int i = 0; i < size; ++i)
	{
		int count = 0; 
		for (int j = 0; j < size; ++j) 
		{
			if (i != j && elements[i] % elements[j] == 0)
			{
				count++;
				break;
			}
		}
		if (count == 1)
		{
			return true;
		}
	}
	return false;
}

Set* finiteSet(std::ifstream& file,uint16_t N) 
{
	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}
	std::ofstream out("first.dat", std::ios::binary);

	if (!out.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	int* elements = new int[N];

	file.read((char*)elements, N * sizeof(int));
	out.write((const char*)elements, N * sizeof(int));

	Set* set = new SetByCriteria(isElementInFiniteSet, elements, N);

	outputNumbersInInterval(set);
	generateSequentially(set);

	delete[]elements;
	out.close();
	file.close();

	return set;

}

Set* notDivisible(std::ifstream &file, uint16_t N) 
{
	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	std::ofstream out("second.dat", std::ios::binary);

	if (!out.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	int* elements = new int[N];
	file.read((char*)elements, N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		if (isElementNotDivisible(elements[i], elements, N))
		{
			out.write((const char*)&elements[i], N * sizeof(int));
		}
	}

	Set* set = new SetByCriteria(isElementNotDivisible, elements, N);

	outputNumbersInInterval(set);
	generateSequentially(set);

	delete[]elements;
	out.close();
	file.close();

	return set;

}

Set* divisible(std::ifstream& file, uint16_t N)
{
	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	std::ofstream out("third.dat", std::ios::binary);

	if (!out.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	int* elements = new int[N];

	file.read((char*)elements, N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		if (isElementDivisibleByOne(elements[i], elements, N))
		{
			out.write((const char*)&elements[i], N * sizeof(int));
		}
	}
	Set* set = new SetByCriteria(isElementDivisibleByOne, elements, N);

	outputNumbersInInterval(set);
	generateSequentially(set);

	delete[]elements;
	out.close();
	file.close();

	return set;
}

Set* pathUnion(std::ifstream& file, uint16_t N)
{
	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	std::ofstream out("fourth.dat", std::ios::binary);

	if (!out.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	Set** sets = new Set * [N];
	MyString* filePaths = new MyString[N];

	for (int i = 0; i < N; i++)
	{
		MyString path;
		char c = '\0';
		while ((c = file.get()) != '\0')
		{
			path += c;
		}

		size_t pathLength = path.length()+1;

		out.write((const char*)&pathLength, sizeof(pathLength));
		out.write(path.c_str(), pathLength);

		sets[i] = createSetFromFile(path);
	}
	Set* unionSet = new UnionOfSets(sets, N,0);

	outputNumbersInInterval(unionSet);
	generateSequentially(unionSet);

	for (int i = 0; i < N; i++)
	{
		delete sets[i];
	}

	delete[]sets;
	delete unionSet;

	out.close();
	file.close();

	return nullptr;

}

Set*pathIntersection(std::ifstream&file, uint16_t N)
{
	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	std::ofstream out("fifth.dat", std::ios::binary);

	if (!out.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	Set** sets = new Set * [N];
	MyString* filepaths = new MyString[N];

	for (int i = 0; i < N; i++)
	{
		MyString filePath;
		char c = '\0';
		while ((c = file.get()) != '\0') {
			filePath += c;
		}
		size_t pathLength = filePath.length()+1;

		out.write((const char*)&pathLength, sizeof(pathLength));
		out.write(filePath.c_str(), pathLength);

		sets[i] = createSetFromFile(filePath);
	}

	Set* intersectSet = new InteresectionOfSets(sets, N,0);

	outputNumbersInInterval(intersectSet);
	generateSequentially(intersectSet);

	for (int i = 0; i < N; i++)
	{
		delete sets[i];
	}

	delete[]sets;
	delete intersectSet;

	out.close();
	file.close();

	return nullptr;

}

Set* createSetFromFile(MyString& filename)
{
	std::ifstream file(filename.c_str(), std::ios::binary);

	if (!file.is_open())
	{
		throw::std::logic_error("File cannot be open!");
	}

	uint16_t  N, T;
	
	file.read((char*)&T, sizeof(T));
	file.read((char*)&N, sizeof(N));

	if (N >= 32) 
	{
		throw std::out_of_range("Error!");
	}

	if (T == 0) 
	{
		finiteSet(file,N);
	}

	else if (T == 1) 
	{
		notDivisible(file, N);
	}

	else if (T == 2) 
	{
		divisible(file, N);
	}

	else if (T == 3) 
	{
		pathUnion(file,N);
	}

	else if (T == 4)
	{
		pathIntersection(file, N);
	}

	else 
	{
	throw std::logic_error("ERROR!");
	}

	file.close();

}

void outputNumbersInInterval(const Set* set)
{
	if (set == nullptr)
	{
		throw std::logic_error("Set is not constructed");
	}
	int a, b;

	std::cin >> a >> b;
	if (a > b)
	{
		throw std::logic_error("Error! Invalid interval!");
	}

	std::cout << "interval : [" << a << " " << b << "]" << std::endl;

	for (int i = a; i <= b; i++)
	{
		if (set->contains(i))
		{
			std::cout << i << std::endl;
		}
	}

}

void generateSequentially(Set* set)
{
	if (set == nullptr)
	{
		throw std::logic_error("Set is not constructed");
	}
	char inputFromUser;
	do
	{
		std::cout << "Next element in range is:" << set->nextElement();
		std::cout << "If you want to quit type 'q'or continue. " << std::endl;
		std::cin >> inputFromUser;

	} while (inputFromUser != 'q');
}