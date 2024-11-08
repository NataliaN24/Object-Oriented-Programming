#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(Predicate pred)
{
	unsigned newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(students[i]))
		{
			students[newSize++] = students[i];
		}
	}
	size = newSize;
}

void FilteredStudentDB::limit(unsigned N)
{
	if (N < size)
	{
		size = N;
	}
}
