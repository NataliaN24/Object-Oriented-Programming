#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

namespace CONSTANSTS
{
	constexpr int FIELD_SIZE = 30;
	constexpr int MAX_FIELDS_ROW = 10;
	constexpr int ROWS_MAX_SIZE = 300;
	constexpr int BUFFER_SIZE = 1024;
	constexpr char SEP = ';';
}

typedef char Field[CONSTANSTS::FIELD_SIZE];
typedef Field Row[CONSTANSTS::MAX_FIELDS_ROW];

struct CSV_Table
{
	Row rows[CONSTANSTS::ROWS_MAX_SIZE];
	size_t rowsCount = 0;
	size_t colsCount = 0;
};

size_t parseRow(const char* row, Row& toReturn)
{
	std::stringstream ss(row);
	size_t currentColCount = 0;
	while (!ss.eof())
	{
		ss.getline(toReturn[currentColCount++], CONSTANSTS::FIELD_SIZE, CONSTANSTS::SEP);
	}
	return currentColCount;
}

CSV_Table parseFromFile(std::ifstream& ifs)
{
	CSV_Table res;
	char rowStr[CONSTANSTS::BUFFER_SIZE];
	while (!ifs.eof())
	{
		ifs.getline(rowStr, CONSTANSTS::BUFFER_SIZE, '\n');
		res.colsCount = parseRow(rowStr, res.rows[res.rowsCount++]);
	}
	return res;
}
CSV_Table parseFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return {};
	}

	return parseFromFile(ifs);
}

void printTable(const CSV_Table& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		for (int j = 0; j < table.colsCount; j++)
		{
			std::cout << table.rows[i][j] << "          ";
		}
		std::cout << std::endl;
	}
}

void saveRowToFile(std::ostream& ofs, const Row& row, size_t collsCount)
{
	for (int i = 0; i < collsCount; i++)
	{
		ofs << row[i];
		if (i != collsCount - 1)
		{
			ofs <<CONSTANSTS::SEP;
		}
	}
}

void saveToFile(std::ostream& ofs, const CSV_Table& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		saveRowToFile(ofs, table.rows[i], table.colsCount);
		if (i != table.rowsCount - 1)
		{
			ofs << std::endl;
		}
	}
}

void saveToFile(const char* fileName, const CSV_Table& table)
{
	std::ofstream ofs(fileName);
	saveToFile(ofs, table);
	ofs.close();
}

int getColumnIndex(const CSV_Table& csvTable, const char* columnName)
{
	assert(csvTable.rowsCount >= 1);
	if (!columnName)
		return -1;

	for (int i = 0; i < csvTable.colsCount; i++)
	{
		if (strcmp(csvTable.rows[0][i], columnName) == 0)
			return i;
	}
	return -1;
}

bool modify(CSV_Table& csv, const char* columnName, const char* newValues, char sep)
{
	int columnIndex = getColumnIndex(csv, columnName);
	if (columnIndex < 0)
		return false;

	std::stringstream ss(newValues);
	int rowIndex = 1;
	while (!ss.eof())
	{
		if (rowIndex > csv.rowsCount)
			break;
		ss.getline(csv.rows[rowIndex++][columnIndex], CONSTANSTS::FIELD_SIZE, sep);
	}
	return true;
}

int main()
{
	CSV_Table myFile = parseFromFile("students.csv");

	printTable(myFile);

	modify(myFile, "Ime", "Katerina|Petya", '|');

	saveToFile("students_new.csv", myFile);
}