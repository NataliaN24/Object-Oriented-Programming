#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#pragma warning (disable:4996)

class ConsolePrinter
{
	bool(*shouldCensore)(char ch);
public:
	ConsolePrinter();
	ConsolePrinter(bool(*pred)(char ch));
	void print(const char* str)const;
};

ConsolePrinter::ConsolePrinter() :shouldCensore([](char ch) {return false; })
{
}

ConsolePrinter::ConsolePrinter(bool(*pred)(char ch)):shouldCensore(pred)
{
}

void ConsolePrinter::print(const char* str) const
{
	while (*str)
	{
		if (shouldCensore(*str))
		{
			std::cout << "*";
		}
		else {
			std::cout << *str;
		}
		
		str++;
	}
	std::cout << std::endl;
}

class NumberWrapper
{
	int n;
	const ConsolePrinter& cp;
public:
	NumberWrapper(int n, const ConsolePrinter& cp);
	int getNumber()const;
	void print()const;
};

NumberWrapper::NumberWrapper(int n, const ConsolePrinter& cp):n(n),cp(cp)
{
}

int NumberWrapper::getNumber() const
{
	return n;
}

void NumberWrapper::print() const
{
	cp.print(std::to_string(n).c_str());
}

class StringWrapper
{
	const char* str;
	const ConsolePrinter& cp;
public:
	StringWrapper(const char* str, const ConsolePrinter& cp);
	void print()const;
};

StringWrapper::StringWrapper(const char* str, const ConsolePrinter& cp):str(str),cp(cp)
{
}

void StringWrapper::print() const
{
	cp.print(str);
}
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

int main()
{
	{
		ConsolePrinter noNumbers([](char ch) {return isDigit(ch); });
		StringWrapper sr("Test3452", noNumbers);
		NumberWrapper nw(1234, noNumbers);
		sr.print();
		nw.print();
	}
	{
		ConsolePrinter censoreAll([](char ch) {return true; });
		StringWrapper sw("Testr13286", censoreAll);
		NumberWrapper nw(1254, censoreAll);
		sw.print();
		nw.print();
	}
}
