#include "Row.h"
#include"iostream"
#include"cstring"
#pragma warning (disable:4996)

Row::Row() : numCells(0)
{
    for (int i = 0; i < CONSTANTS::ROW_MAX_SIZE_CELLS; ++i) 
    {
        cells[i][0] = '\0';
        isHeader[i] = false;
    }
};

Row::~Row() {};

void Row::setCell(size_t index, const char* value, bool header) 
{
    if (index < CONSTANTS::ROW_MAX_SIZE_CELLS)
    {
        strncpy(cells[index], value, CONSTANTS::CELL_MAX_SIZE - 1);
        cells[index][CONSTANTS::CELL_MAX_SIZE - 1] = '\0';
        isHeader[index] = header;

        if (index >= numCells) 
        {
            numCells = index + 1;
        }
    }
}

size_t Row::cellsCount() const 
{
    return numCells;
}