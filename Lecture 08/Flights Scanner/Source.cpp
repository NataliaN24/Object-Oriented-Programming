#include"FlightsScanner.h"

int main()
{
    FlightsScanner scanner("input.txt", "output.txt", 10);
    scanner.run();
    return 0;
}