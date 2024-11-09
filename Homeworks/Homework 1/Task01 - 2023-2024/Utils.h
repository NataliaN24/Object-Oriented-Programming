#pragma once

bool isDigit(char ch);

char convertIntoAsciiCode(const char* ptr, int& count);

namespace CONSTANTS {
    constexpr int CELL_MAX_SIZE = 50;
    constexpr int ROW_MAX_SIZE_CELLS = 15;
    constexpr int TABLE_MAX_SIZE_ROWS = 100;
    constexpr int BUFFER_SIZE = 1024;

    constexpr char SPACE_SYMBOL = ' ';
    constexpr char NEW_LINE_SYMBOL = '\n';
    constexpr char TERMINATING_NULL = '\0';
    constexpr char DS_SYMBOL = '#';
    constexpr char AMPERSAND_SYMBOL = '&';
    constexpr char LINE_SYMBOL = '|';
    constexpr char HEADER_SYMBOL = '*';

    constexpr int TWO_SYMOBLS_AFTER_AMPERSAND = 2;
    constexpr int ONE_SYMBOL_AFTER_AMPERSAND = 1;//this is done to move pointer in the parse function with one position after & to reiew the next char after & if it is #

    constexpr char TABLE_START_TAG[] = "<table>";
    constexpr char ROW_START_TAG[] = "<tr>";
    constexpr char HEADER_START_TAG[] = "<th>";
    constexpr char CELL_START_TAG[] = "<td>";

    constexpr char TABLE_END_TAG[] = "</table>";
    constexpr char ROW_END_TAG[] = "</tr>";
    constexpr char CELL_END_TAG[] = "</td>";
    constexpr char HEADER_END_TAG[] = "</th>";
    
    constexpr int TAGS_THAT_HAVE_FOUR_SYMBOLS = 4;//FOR EXAMPLE <tr> has 4 symbols
    constexpr int TAGS_THAT_HAVE_FIVE_SYMBOLS = 5;

    const char FILE_NAME[] = "table.txt";
}