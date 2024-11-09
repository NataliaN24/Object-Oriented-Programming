#pragma once
#include"Utils.h"

typedef char Cell[CONSTANTS::CELL_MAX_SIZE];

struct Row 
{
    bool isHeader[CONSTANTS::ROW_MAX_SIZE_CELLS];
    Cell cells[CONSTANTS::ROW_MAX_SIZE_CELLS];
    size_t numCells;
   

    Row();

    void setCell(size_t index, const char* value, bool header);

    size_t cellsCount() const;

    ~Row();
};