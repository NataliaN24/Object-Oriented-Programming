#pragma once
#pragma once
//Natalia Nakollofski  1MI8000034  GROUP 1 SI
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
const int MAX_SYMBOLS = 20;
const int MAX_COLUMNS = 10;
const int MAX_COL_WIDTH = 50;
const int MAX_ROWS = 50;
const int BUFF_SIZE = 1024;
const char* filename = "table.md";


struct Table {
	char headers[MAX_COLUMNS][MAX_COL_WIDTH];
	char table[MAX_ROWS][MAX_COLUMNS][MAX_COL_WIDTH];
	char alignments[MAX_COLUMNS];
	int num_of_rows;
	int num_of_cols;
};
	void MyStrcat(char* dest, const char* src);
	void MyStrcpy(char* dest, const char* src);
	size_t myStrlen(const char* word);
	int myStrcmp(const char* ch1, const char* ch2);
	char* myStrncpy(char* dest, const char* src, size_t n);
	Table CreateTable(int num_of_rows, int num_of_cols);
	void loadFromFile(const char* filename, Table& table);
	void loadFromFile(const char* filename, Table& table);
	void printDataOfTable(const Table& table, int* max_col_width, int startRow = 0, int cntRows=-1 );
	void CalculateMaxOfEachCol(const Table& table, int* max_col_width);
	void printHeaders(const Table& table, int* max_col_width);
	void printSeparator(const Table& table, int* max_col_width);
	void printTable(const Table& table);
	int FindTheIndexPosition(const Table& table, int index, const char* name);
	void renameAColumn(Table& table, const char* oldName, const char* newName);
	void addRow(Table& table, char** rowValues);
	void changeRow(Table& table, int numOfRow, const char* colName, const char* colValue);
	void changeColValue(Table& table, const char* colName, const char* colValueToBEchanged, const char* NewcolValue);
	void SelectWhere(const Table& table, const char* colName, const char* colValue);
	void saveToFile(const char* filename, const Table& table);
