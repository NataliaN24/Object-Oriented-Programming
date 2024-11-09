#include<iostream>
#include<fstream>
#include"MarkdownTable.h"
//Natalia Nakollofski  1MI8000034  GROUP 1 SI
using std::cout;
using std::cin;
using std::endl;

void MyStrcat(char* dest, const char* src) { //function from an internet source
	int dest_len = strlen(dest);
	int src_len = strlen(src);
	for (int i = 0; i < src_len; ++i) {
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + src_len] = '\0';
}
void MyStrcpy(char* dest, const char* src) {//function from an internet source
	size_t index = 0;
	while (src[index] != '\0') {
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
}
size_t myStrlen(const char* word) {//function from an internet source
	size_t length = 0;
	while (*word != '\0') {
		length++;
		word++;
	}
	return length;
}
int myStrcmp(const char* ch1, const char* ch2) {//function from an internet source
	while (*ch1 && (*ch1 == *ch2)) {
		ch1++;
		ch2++;
	}
	return*(const unsigned char*)ch1 - *(const unsigned char*)ch2;

}
char* myStrncpy(char* dest, const char* src, size_t n) { //function from an internet source
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}
	for (i = 0; i < n; i++) {
		dest[i] = '\0';
	}
	return dest;
}
Table CreateTable(int num_of_rows, int num_of_cols) {
	Table table;
	table.num_of_rows = num_of_rows;
	table.num_of_cols = num_of_cols;
	for (int j = 0; j < num_of_cols; j++) {
		cout << "Enter header name for column " << j + 1 << ": ";
		cin.getline(table.headers[j], MAX_COL_WIDTH);
	}
	for (int i = 0; i < num_of_rows; i++) {
		for (int j = 0; j < num_of_cols; j++) {
			cout << "Enter value for row " << i + 1 << ", column " << j + 1 << ": ";
			cin.getline(table.table[i][j], MAX_COL_WIDTH);
		}
	}
	return table;
}
void loadFromFile(const char* filename, Table& table) {
	ifstream in(filename, std::ios::in);
	if (!in.is_open()) {
		cout << "ERROR OPENING THIS FILE" << endl;
		return;
	}


	char line[1024];
	in.getline(line, 1024);
	char* p = line;
	int col = 0;
	while (*p) {
		if (*p == '|' || *p == ' ') {
			++p;
			continue;
		}
		char* start = p;
		while (*p && *p != '|') {
			++p;
		}
		*p = '\0';
		char* end = p - 1;
		while (*end == ' ') {
			*end = '\0';
			--end;

		}
		MyStrcpy(table.headers[col++], start);
		++p;
	}
	table.num_of_cols = col;
	int row = 0;
	in.getline(line, 1024);
	while (in.getline(line, 1024)) {
		if (line[0] == '|') {
			p = line + 1;
			col = 0;
			while (*p) {
				if (*p == ' ') {
					++p;
					continue;
				}
				char* start = p;
				while (*p && *p != '|') {
					++p;
				}
				*p = '\0';
				char* end = p - 1;
				while (*end == ' ') {
					*end = '\0';
					--end;
				}
				MyStrcpy(table.table[row][col++], start);
				++p;
			}
			++row;
		}
	}
	table.num_of_rows = row;

	in.close();
}
void printDataOfTable(const Table& table, int* max_col_width, int startRow , int cntRows ) {
	int endRow = table.num_of_rows;
	if (cntRows != -1)
		endRow = startRow + cntRows;
	for (int i = startRow; i < endRow; i++) {
		for (int j = 0; j < table.num_of_cols; j++) {
			cout << "| ";
			int width = myStrlen(table.table[i][j]);
			int padding = max_col_width[j] - width;
			if (table.alignments[j] == 'r') {
				for (int k = 0; k < padding; k++) {
					cout << " ";
				}
			}
			cout << table.table[i][j];
			if (table.alignments[j] == 'c') {
				for (int k = 0; k < padding; k++) {
					cout << " ";
				}
			}
			cout << " ";
			if (table.alignments[j] != 'r' && table.alignments[j] != 'c') {
				for (int k = 0; k < padding; k++) {
					cout << " ";
				}
			}
		}
		cout << "|" << endl;
	}
}


void CalculateMaxOfEachCol(const Table& table, int* max_col_width) {
	for (int j = 0; j < table.num_of_cols; j++) {
		max_col_width[j] = myStrlen(table.headers[j]);
		for (int i = 0; i < table.num_of_rows; i++) {
			int width = myStrlen(table.table[i][j]);
			if (width > max_col_width[j]) {
				max_col_width[j] = width;
			}
		}
	}
}
void printHeaders(const Table& table, int* max_col_width) {
	for (int j = 0; j < table.num_of_cols; j++) {
		cout << "| " << table.headers[j];
		for (int k = 0; k < max_col_width[j] - myStrlen(table.headers[j]) + 1; k++) {
			cout << " ";
		}
	}
	cout << "|" << endl;

}
void printSeparator(const Table& table, int* max_col_width) {
	for (int j = 0; j < table.num_of_cols; j++) {
		cout << "|";
		for (int k = 0; k < max_col_width[j] + 2; k++) {
			cout << "-";
		}
	}
}

void printTable(const Table& table) {
	int max_col_width[MAX_COLUMNS];
	CalculateMaxOfEachCol(table, max_col_width);
	printHeaders(table, max_col_width);
	printSeparator(table, max_col_width);
	cout << "|" << endl;
	printDataOfTable(table, max_col_width);
}
int FindTheIndexPosition(const Table& table, int index, const char* name) {
	for (int i = 0; i < table.num_of_cols; i++) {
		if (myStrcmp(table.headers[i], name) == 0) {
			return i;
		}
	}
	return -1;

}
void renameAColumn(Table& table, const char* oldName, const char* newName) {
	int columnToBeRenamed = -1;
	for (int i = 0; i < table.num_of_cols; ++i) {
		if (myStrcmp(table.headers[i], oldName) == 0) {
			columnToBeRenamed = i;
			break;
		}
	}
	if (columnToBeRenamed != -1) {
		MyStrcpy(table.headers[columnToBeRenamed], newName);
		cout << "Operation successfully executed!" << endl;
	}
	else {
		cout << "ERROR: Column not found" << endl;
	}
}

void addRow(Table& table, char** rowValues) {
	if (table.num_of_rows >= MAX_ROWS) {
		cout << "ERROR: Table is full" << endl;
		return;
	}

	for (int i = 0; i < table.num_of_cols; i++) {

		MyStrcpy(table.table[table.num_of_rows][i], rowValues[i]);

	}

	table.num_of_rows++;

	cout << "Operation successfully executed!" << endl;
}
void changeRow(Table& table, int numOfRow, const char* colName, const char* colValue) {
	if (numOfRow<1 || numOfRow>table.num_of_rows || numOfRow > MAX_ROWS) {
		cout << "Error." << endl;
		return;
	}

	int index = -1;
	index = FindTheIndexPosition(table, index, colName);
	if (index != -1) {
		MyStrcpy(table.table[numOfRow - 1][index], colValue);
		cout << "Operation successfully executed!" << endl;
	}
	else {

		std::cout << "Invalid column name!" << std::endl;
		return;
	}
}

void changeColValue(Table& table, const char* colName, const char* colValueToBEchanged, const char* NewcolValue) {

	ifstream file(filename, std::ios::in);
	if (!file.is_open()) {
		cout << "error";
		return;
	}
	int index1 = -1;
	index1 = FindTheIndexPosition(table, index1, colName);

	if (index1 != -1) {
		for (int i = 0; i < table.num_of_rows; i++) {
			if (myStrcmp(table.table[i][index1], colValueToBEchanged) == 0) {
				MyStrcpy(table.table[i][index1], NewcolValue);
				cout << "Operation successfully executed!" << std::endl;
				return;
			}
		}
	}

	cout << "Value not found in column" << endl;
	file.close();
}

void SelectWhere(const Table& table, const char* colName, const char* colValue) {
	int colIndex = -1;
	colIndex = FindTheIndexPosition(table, colIndex, colName);
	if (colIndex == -1) {
		cout << "Invalid column name!" << endl;
		return;
	}

	bool found = false;
	int max_col_width[MAX_COLUMNS];
	CalculateMaxOfEachCol(table, max_col_width);
	for (int i = 0; i < table.num_of_rows; i++) {
		if (strcmp(table.table[i][colIndex], colValue) == 0) {
			if (!found) {
				printHeaders(table, max_col_width);
				printSeparator(table, max_col_width);
				cout << "|" << endl;
				found = true;
			}
			printDataOfTable(table, max_col_width, i, 1);
		}
	}

	if (!found) {
		cout << "No rows found with the specified value." << endl;
	}
}

void saveToFile(const char* filename, const Table& table) {
	ofstream out(filename, std::ios::out);
	if (!out.is_open()) {
		cout << "ERROR OPENING THIS FILE" << endl;
		return;
	}
	int max_col_width[MAX_COLUMNS] = { 0 };
	for (int j = 0; j < table.num_of_cols; j++) {
		max_col_width[j] = strlen(table.headers[j]);
		for (int i = 0; i < table.num_of_rows; i++) {
			int width = strlen(table.table[i][j]);
			if (width > max_col_width[j]) {
				max_col_width[j] = width;
			}
		}
	}
	for (int j = 0; j < table.num_of_cols; j++) {
		out << "| " << table.headers[j];
		for (int k = 0; k < max_col_width[j] - strlen(table.headers[j]) + 1; k++) {
			out << " ";
		}
	}
	out << "|" << endl;
	for (int j = 0; j < table.num_of_cols; j++) {
		out << "|";
		for (int k = 0; k < max_col_width[j] + 2; k++) {
			out << "-";
		}
	}
	out << "|" << endl;
	for (int i = 0; i < table.num_of_rows; i++) {
		for (int j = 0; j < table.num_of_cols; j++) {
			out << "| " << table.table[i][j];
			size_t size = myStrlen(table.table[i][j]);
			for (int k = 0; k < max_col_width[j] - size + 1; k++) {
				out << " ";
			}
		}
		out << "|" << endl;
	}
	out.close();

}
int main() {
	Table myTable;

	int numOfRows, numOfCols = 0;
	int option = 0;
	do {
		cout << "MENU:" << endl;
		cout << "--CHOOSE ONE OF THE OPTIONS BELOW--" << endl;
		cout << "1.Create a table." << endl;
		cout << "2.Load a table." << endl;
		cout << "3.Save table to file" << endl;
		cout << "4.Print the table." << endl;
		cout << "5.Change the name of the column." << endl;
		cout << "6.Add a new row." << endl;
		cout << "7.Change a value in the column by a given row number and column name." << endl;
		cout << "8.Change a value in the column by a supplied column name and value." << endl;
		cout << "9.Selection:Print all rows that have a given value column." << endl;
		cout << "10.Exit" << endl;
		cin >> option;
		cin.ignore();

		switch (option) {
		case 1:
			int rows, cols;
			cout << "Enter number of rows: ";
			cin >> rows;
			cout << "Enter number of columns: ";
			cin >> cols;
			cin.ignore(); 
			myTable = CreateTable(rows, cols);
			saveToFile(filename, myTable);
			break;
		case 2:
			loadFromFile(filename, myTable);
			break;
		case 3:
			saveToFile(filename, myTable);
			break;
		case 4:
			loadFromFile(filename, myTable);
			printTable(myTable);

			break;
		case 5:
			loadFromFile(filename, myTable);
			char oldName[MAX_SYMBOLS];
			char newName[MAX_SYMBOLS];
			cout << "Enter the name of the column to be changed:" << endl;
			cin.getline(oldName, MAX_SYMBOLS);
			cout << "Enter  new name:" << endl;
			cin.getline(newName, MAX_SYMBOLS);

			renameAColumn(myTable, oldName, newName);
			saveToFile(filename, myTable);
			break;
		case 6:
			loadFromFile(filename, myTable);
			char* rowValues[MAX_COLUMNS];
			for (int i = 0; i < myTable.num_of_cols; i++) {
				cout << "Enter value for  each column : ";
				char buffer[1024];
				cin.getline(buffer, 1024);

				rowValues[i] = new char[myStrlen(buffer) + 1];
				MyStrcpy(rowValues[i], buffer);
			}

			addRow(myTable, rowValues);
			saveToFile(filename, myTable);
			break;
		case 7:
			loadFromFile(filename, myTable);
			int numOfRowToBeChanged;
			cout << "Enter the number of row to be changed:" << endl;
			cin >> numOfRowToBeChanged;
			cin.ignore();
			char columnName[MAX_SYMBOLS];
			cout << "Enter the name of column:" << endl;
			cin.getline(columnName, MAX_SYMBOLS);
			char colValue[MAX_SYMBOLS];
			cout << "Enter  new name:" << endl;
			cin.getline(colValue, MAX_SYMBOLS);

			changeRow(myTable, numOfRowToBeChanged, columnName, colValue);
			saveToFile(filename, myTable);
			break;
		case 8:
			loadFromFile(filename, myTable);
			char colName[MAX_SYMBOLS];
			char colValueToBeChanged[MAX_SYMBOLS];
			char newColValue[MAX_SYMBOLS];
			cout << "Enter the name of  the column where you want to make changes:" << endl;
			cin.getline(colName, MAX_SYMBOLS);
			cout << "Enter the value where you want to make changes: " << endl;
			cin.getline(colValueToBeChanged, MAX_SYMBOLS);
			cout << "Enter the new name of the column:" << endl;
			cin.getline(newColValue, MAX_SYMBOLS);

			changeColValue(myTable, colName, colValueToBeChanged, newColValue);
			saveToFile(filename, myTable);
			printTable(myTable);
			break;
		case 9:
			loadFromFile(filename, myTable);
			char ColName[MAX_SYMBOLS];
			char Col_value[MAX_SYMBOLS];
			cout << "Enter the name of  the column :" << endl;
			cin.getline(ColName, MAX_SYMBOLS);
			cout << "Enter the value of column :" << endl;
			cin.getline(Col_value, MAX_SYMBOLS);

			SelectWhere(myTable, ColName, Col_value);
			break;
		case 10:
			cout << "Good bye!" << endl;
			break;
		default:
			cout << "Invalid option.Try again!" << endl;
			break;
		}
	} while (option != 10);
	return 0;

}
