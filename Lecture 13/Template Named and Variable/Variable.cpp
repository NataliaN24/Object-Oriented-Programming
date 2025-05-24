#include"Variable.h"

Variable::Variable(const char* name, int data):Named<int>(name,data) {
}

int Variable:: operator*()const
{
	return getData();
}
Variable& Variable:: operator=(const Variable& right) 
{
	if (this != &right)
	{
		this->setData(right.getData());
	}
	return *this;
}

bool operator==(const Variable& left, const Variable& right)
{
	return strcmp(left.getName(), right.getName()) == 0 &&left.getData()==right.getData();
}
bool operator!=(const Variable& left, const Variable& right) {
	return !(left == right);
}
