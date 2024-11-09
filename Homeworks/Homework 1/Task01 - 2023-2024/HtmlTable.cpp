#include "HtmlTable.h"
#include <sstream>
#include <cstring>
#pragma warning(disable:4996)

void HtmlTable::calculateColumnWidths() 
{
    for (size_t j = 0; j < columnCount; ++j) 
    {
        size_t maxCellWidth = 0;
        for (size_t i = 0; i < rowsCount; ++i) 
        {
            size_t cellWidth = strlen(rows[i].cells[j]);

            if (cellWidth > maxCellWidth) 
            {
                maxCellWidth = cellWidth;
            }
        }
        columnWidths[j] = maxCellWidth;
    }
}

void  HtmlTable::addRow(const Row& newRow) 
{
    if (rowsCount < CONSTANTS::TABLE_MAX_SIZE_ROWS) 
    {
        rows[rowsCount++] = newRow;

        if (newRow.cellsCount() > columnCount)
        {
            columnCount = newRow.cellsCount();
        }

        calculateColumnWidths();
    }
}

void HtmlTable::print() const
{
    for (size_t i = 0; i < rowsCount; ++i) 
    {
        std::cout << CONSTANTS::LINE_SYMBOL;

        for (size_t j = 0; j < columnCount; ++j)
        {
            size_t cellWidth = strlen(rows[i].cells[j]);
            size_t padding = columnWidths[j] - cellWidth;

            if (rows[i].isHeader[j]) 
            {
                std::cout << CONSTANTS::HEADER_SYMBOL;
                std::cout << rows[i].cells[j];
                for (size_t k = 0; k < padding; ++k) 
                {
                    std::cout << CONSTANTS::SPACE_SYMBOL;
                }
                std::cout << CONSTANTS::HEADER_SYMBOL << CONSTANTS::LINE_SYMBOL;
            }
            else 
            {
                std::cout << CONSTANTS::SPACE_SYMBOL;
                std::cout << rows[i].cells[j];

                for (size_t k = 0; k < padding; ++k) 
                {
                    std::cout << CONSTANTS::SPACE_SYMBOL;
                }
                std::cout << CONSTANTS::SPACE_SYMBOL << CONSTANTS::LINE_SYMBOL;
            }
        }
        std::cout << std::endl;
    }
}

void HtmlTable::parseHtmlTable(HtmlTable& html, std::ifstream& file) 
{
    char buffer[CONSTANTS::BUFFER_SIZE];
    while (file.getline(buffer, CONSTANTS::BUFFER_SIZE)) 
    {
        const char* ptr = buffer;

        while (*ptr && (*ptr == CONSTANTS::SPACE_SYMBOL || *ptr == CONSTANTS::NEW_LINE_SYMBOL || *ptr == CONSTANTS::TERMINATING_NULL)) 
        {
            ++ptr;
        }

        if (strncmp(ptr, CONSTANTS::ROW_START_TAG, CONSTANTS::TAGS_THAT_HAVE_FOUR_SYMBOLS) == 0) 
        {
            Row newRow;
            size_t columnCount = 0;

            while (file.getline(buffer, CONSTANTS::BUFFER_SIZE))
            {
                ptr = buffer;
                while (*ptr && (*ptr == CONSTANTS::SPACE_SYMBOL || *ptr == CONSTANTS::NEW_LINE_SYMBOL || *ptr == CONSTANTS::TERMINATING_NULL))
                {
                    ++ptr;
                }

                if (strncmp(ptr, CONSTANTS::ROW_END_TAG, CONSTANTS::TAGS_THAT_HAVE_FIVE_SYMBOLS) == 0) 
                {
                    break;
                }

                std::stringstream cellContent;
                if (strncmp(ptr, CONSTANTS::HEADER_START_TAG, CONSTANTS::TAGS_THAT_HAVE_FOUR_SYMBOLS) == 0 || strncmp(ptr, CONSTANTS::CELL_START_TAG, CONSTANTS::TAGS_THAT_HAVE_FOUR_SYMBOLS) == 0)
                {
                    bool isHeaderCell = strncmp(ptr, CONSTANTS::HEADER_START_TAG, CONSTANTS::TAGS_THAT_HAVE_FOUR_SYMBOLS) == 0; 

                    ptr += CONSTANTS::TAGS_THAT_HAVE_FOUR_SYMBOLS;

                    while (*ptr && strncmp(ptr, CONSTANTS::CELL_END_TAG, CONSTANTS::TAGS_THAT_HAVE_FIVE_SYMBOLS) != 0 && strncmp(ptr, CONSTANTS::HEADER_END_TAG, CONSTANTS::TAGS_THAT_HAVE_FIVE_SYMBOLS) != 0)
                    {
                        if (*ptr == CONSTANTS::AMPERSAND_SYMBOL && *(ptr + CONSTANTS::ONE_SYMBOL_AFTER_AMPERSAND) == CONSTANTS::DS_SYMBOL && *(ptr + CONSTANTS::TWO_SYMOBLS_AFTER_AMPERSAND) != CONSTANTS::TERMINATING_NULL) 
                        {
                            ptr += CONSTANTS::TWO_SYMOBLS_AFTER_AMPERSAND;
                            int count = 0;
                            char asciiNumber = convertIntoAsciiCode(ptr, count);
                            cellContent << asciiNumber;
                            ptr += count;
                        }
                        cellContent << *ptr;
                        ++ptr;
                    }
                    newRow.setCell(columnCount++, cellContent.str().c_str(), isHeaderCell);
                }
            }
            html.addRow(newRow);
        }
    }
}

void  HtmlTable::save_table(const char* file_path, const HtmlTable& table) const
{
    std::ofstream outputFile( file_path,std::ios::out);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }

    outputFile << CONSTANTS::TABLE_START_TAG << std::endl;

    for (size_t i = 0; i < table.rowsCount; ++i)
    {
        outputFile <<"  "<<CONSTANTS::ROW_START_TAG << std::endl;
        for (size_t j = 0; j < table.columnCount; ++j)
        {
            if (table.rows[i].isHeader[j]) 
            {
                outputFile << "    "<<CONSTANTS::HEADER_START_TAG <<table.rows[i].cells[j] << CONSTANTS::HEADER_END_TAG<< std::endl;
            }
            else 
            {
                outputFile << "    "<< CONSTANTS::CELL_START_TAG<< table.rows[i].cells[j] << CONSTANTS::CELL_END_TAG << std::endl;
            }
        }
        outputFile << "  "<< CONSTANTS::ROW_END_TAG<< std::endl;
    }

    outputFile << CONSTANTS::TABLE_END_TAG << std::endl;

    outputFile.close();
}

void  HtmlTable::addNewRow(size_t index, const Cell* values,const  bool* isHeader) 
{
    if (index < CONSTANTS::TABLE_MAX_SIZE_ROWS&& index >= 1) 
    {

        for (size_t i = rowsCount; i > index - 1; --i) 
        {
            rows[i] = rows[i - 1];
        }

        size_t newIndex = index - 1;

        for (size_t i = 0; i < columnCount; ++i) 
        {
            if (isHeader[i]) 
            {
                rows[newIndex].isHeader[i] = true;

                if (values[i][0] != CONSTANTS::TERMINATING_NULL) 
                {
                    strncpy(rows[newIndex].cells[i], values[i], CONSTANTS::CELL_MAX_SIZE - 1);
                }
                else 
                {
                    rows[newIndex].cells[i][0] = CONSTANTS::TERMINATING_NULL;
                }
            }
            else 
            {
                if (i < rows[newIndex].cellsCount()) 
                {
                    if (values[i][0] != CONSTANTS::TERMINATING_NULL)
                    {
                        strncpy(rows[newIndex].cells[i], values[i], CONSTANTS::CELL_MAX_SIZE - 1);
                    }

                    else 
                    {
                        rows[newIndex].cells[i][0] = CONSTANTS::TERMINATING_NULL;
                    }
                }

                else 
                {
                    rows[newIndex].cells[i][0] = CONSTANTS::TERMINATING_NULL;
                }
            }

            size_t cellWidth = strlen(rows[newIndex].cells[i]);
            if (cellWidth > columnWidths[i])
            {
                columnWidths[i] = cellWidth;
            }
        }

        ++rowsCount;
    }
}

void  HtmlTable::removeRow(size_t index)
{
    if (index >= 1 && index <= rowsCount)
    {
        for (size_t i = index - 1; i < rowsCount - 1; ++i)
        {
            rows[i] = rows[i + 1];
        }
        --rowsCount;
    }
}

void  HtmlTable::editCell(size_t rowNumber, size_t colNumber, const char* newValue, bool isHeader)
{
    if (rowNumber >= 1 && rowNumber <= rowsCount && colNumber >= 1 && colNumber <= columnCount)
    {
        size_t rowIndex = rowNumber - 1;
        size_t colIndex = colNumber - 1;

        if (isHeader)
        {
            rows[rowIndex].isHeader[colIndex] = true;
        }

        if (rows[rowIndex].isHeader[colIndex])
        {
            if (colIndex == colNumber - 1)
            {
                strncpy(rows[rowIndex].cells[colIndex], newValue, CONSTANTS::CELL_MAX_SIZE - 1);
                rows[rowIndex].cells[colIndex][CONSTANTS::CELL_MAX_SIZE - 1] = CONSTANTS::TERMINATING_NULL;
            }
        }
        else
        {
            strncpy(rows[rowIndex].cells[colIndex], newValue, CONSTANTS::CELL_MAX_SIZE - 1);
            rows[rowIndex].cells[colIndex][CONSTANTS::CELL_MAX_SIZE - 1] = CONSTANTS::TERMINATING_NULL;
        }
        calculateColumnWidths();
    }
}

HtmlTable:: ~HtmlTable() {}