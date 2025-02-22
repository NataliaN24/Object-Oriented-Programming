//Solution number 1------------------------------------------------------------------------------
#include <iostream>
#pragma warning  (disable:4996)
#include <cstring>

enum class ErrorCode {
	isNullptr,
	isOkay,
	isDirty,
	isEmpty
};

struct Result
{
	ErrorCode code;
	int parsedNumber;
};

bool isValid(const char* str)
{
	bool isValidNumber = true;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i]<='0' || str[i]>='9') {
			isValidNumber = false;
			break;
		}
	}
	return isValidNumber;
}
int convertStrToNumber(const char* str)
{
	int number = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		number *= 10;
		number += str[i] - '0';
	}
	return number;
}

ErrorCode parseStringToNumbers(const char* str)
{
	
	if (!str)
	{
		return ErrorCode::isNullptr;
	}
	else if (std::strlen(str) == 0)
	{
		return ErrorCode::isEmpty;
	}
	else if (isValid(str)) {
		return ErrorCode::isOkay;
	}
	else {
		return ErrorCode::isDirty;
	}
}
void printResults( Result& res,const char*str)
{
	if (res.code == ErrorCode::isOkay)
	{
		res.parsedNumber = convertStrToNumber(str);
		std::cout << res.parsedNumber << " " << "String is okay" << std::endl;
	}
	else if (res.code == ErrorCode::isDirty)
	{
		std::cout <<"String is dirty" << std::endl;
	}
	else if (res.code == ErrorCode::isEmpty)
	{
		std::cout << "String is empty" << std::endl;
	}
	else if (res.code == ErrorCode::isNullptr)
	{
		std::cout << "String is nullptr" << std::endl;
	}

}

int main() {
	char str[50];
	std::cin >> str;
	Result result;
	result.code = parseStringToNumbers(str);
	printResults(result, str);
}

//Solution number 2------------------------------------------------------------------------------
#include <iostream>

enum class ErrorCode
{
	NoError,
	NullptrError,
	DirtyTextError,
	EmptyTextError,
};

struct ParseResult
{
	ErrorCode errorCode;
	int number;
};

ParseResult convertTextToNumber(const char* text)
{
	int number = 0;

	for (int i = 0; text[i]; i++)
	{
		char symbol = text[i];

		if ('0' <= symbol && symbol <= '9')
		{
			number *= 10;
			number += (symbol - '0');
		}
		else
		{
			return ParseResult{ ErrorCode::DirtyTextError };
		}
	}

	return ParseResult{ ErrorCode::NoError, number };
}

ParseResult parseNumber(const char* text)
{
	if (!text)
	{
		return { ErrorCode::NullptrError }; // the name ParseResult may be ommited
	}

	int textLength = strlen(text);

	if (textLength == 0)
	{
		return ParseResult{ ErrorCode::EmptyTextError };
	}

	return convertTextToNumber(text);
}

const char* getErrorDescription(ErrorCode errorCode)
{
	switch (errorCode)
	{
	case ErrorCode::NullptrError:
		return "Text cannot be nullptr";
	case ErrorCode::DirtyTextError:
		return "Text contains dirty symbols";
	case ErrorCode::EmptyTextError:
		return "Text cannot be empty";
	}

	return nullptr;
}

bool isError(ErrorCode errorCode)
{
	switch (errorCode)
	{
	case ErrorCode::NoError:
		return false;
	}

	return true;
}

int main()
{
	char text[32]="";
	std::cin >> text;

	ParseResult parseResult = parseNumber(text);

	if (isError(parseResult.errorCode))
	{
		std::cout << getErrorDescription(parseResult.errorCode) << std::endl;
	}
	else
	{
		std::cout << parseResult.number;
	}
}
