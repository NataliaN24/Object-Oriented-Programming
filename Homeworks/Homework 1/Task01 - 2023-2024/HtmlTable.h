#pragma once
#include"Row.h"
#include"Utils.h"
#include<fstream>
#include<iostream>

class HtmlTable
{
private:

    size_t rowsCount = 0;
    size_t columnCount = 0;
    size_t columnWidths[CONSTANTS::ROW_MAX_SIZE_CELLS] = { 0 };
    Row rows[CONSTANTS::TABLE_MAX_SIZE_ROWS];
   
public:

    HtmlTable() = default;
   
    void parseHtmlTable(HtmlTable& html, std::ifstream& file);

    void addRow(const Row& newRow);

    void save_table(const char* file_path, const HtmlTable& table)const ;

    void addNewRow(size_t index, const Cell* values, const bool* isHeader);

    void removeRow(size_t index);

    void editCell(size_t rowNumber, size_t colNumber, const char* newValue, bool isHeader);

    void print() const;

    void calculateColumnWidths();

    ~HtmlTable();

};