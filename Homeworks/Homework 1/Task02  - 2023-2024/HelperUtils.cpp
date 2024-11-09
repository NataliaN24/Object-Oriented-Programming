#include "HelperUtils.h"

size_t getFileSize(std::ifstream& f) //This function is taken ready from github of A.Dimitriev
{
    size_t currentPos = f.tellg();
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(currentPos);

    return size;

}