#include "Utils.h"

const char* setChar(char* ch1, const char* ch2, int len)
{
	if (std::strlen(ch2) < len)
	{
		strcpy(ch1, ch2);
		ch1[len - 1] = '\0';
		return ch1;
	}
	else {
		throw errorCode::InvalidInput;
	}
}