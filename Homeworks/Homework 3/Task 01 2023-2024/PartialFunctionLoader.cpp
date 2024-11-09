#include "PartialFunctionLoader.h"

namespace CONSTANTS
{
   constexpr size_t  PATH_SIZE = 1024;
   constexpr size_t LIMIT_OF_N = 32;
   constexpr char TERMINATING_NULL = '\0';
}

PartialFunction* PartialFunctionLoader::loadFunction(const char* filename) 
{
    std::ifstream file(filename, std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("Error opening file!");
    }

    uint16_t N, T;

    file.read((char*)(&N), sizeof(N));
    file.read((char*)(&T), sizeof(T));

    if (N > CONSTANTS::LIMIT_OF_N) 
    {
        throw std::out_of_range("N exceeds the maximum allowed value!");
        return nullptr;
    }

    switch (T) 
    {
    case 0:
        return handleCase0(file, N);
    case 1:
        return handleCase1(file, N);
    case 2:
        return handleCase2(file, N);
    case 3:
        return handleCase3(file, N);
    case 4:
        return handleCase4(file, N);
    default:
        throw std::runtime_error("Unknown type T!");
    }
}

PartialFunction* PartialFunctionLoader::handleCase0(std::ifstream& file, uint16_t N)
{ 
    int32_t inputs[CONSTANTS::LIMIT_OF_N];
    int32_t results[CONSTANTS::LIMIT_OF_N];

    file.read((char*)inputs, N* sizeof(int32_t));
    file.read((char*)results, N * sizeof(int32_t));
    
    return new PartialFunctionByCriteria<Case0>(Case0(inputs, results, N));
}

PartialFunction* PartialFunctionLoader::handleCase1(std::ifstream& file, uint16_t N)
{
    int32_t undefinedInputs[CONSTANTS::LIMIT_OF_N];

    file.read((char*) undefinedInputs, N* sizeof(int32_t));

    return new PartialFunctionByCriteria<Case1>(Case1(undefinedInputs, N));
}

PartialFunction* PartialFunctionLoader::handleCase2(std::ifstream& file, uint16_t N)
{
    int32_t specificArgs[CONSTANTS::LIMIT_OF_N];
    
    file.read((char*) specificArgs, N * sizeof(int32_t));

    return new PartialFunctionByCriteria<Case2>(Case2(specificArgs, N));
}

PartialFunction* PartialFunctionLoader::handleCase3(std::ifstream& file, uint16_t N)
{
    PartialFunction* functions[CONSTANTS::LIMIT_OF_N];

    for (uint16_t i = 0; i < N; ++i)
    {
        char path[CONSTANTS::PATH_SIZE];
        file.getline(path, CONSTANTS::PATH_SIZE, CONSTANTS::TERMINATING_NULL);
        functions[i] = loadFunction(path);
    }
    return new MaximumOfPartialFunctions(functions, N);
}

PartialFunction* PartialFunctionLoader::handleCase4(std::ifstream& file, uint16_t N)
{
     PartialFunction* functions[CONSTANTS::LIMIT_OF_N];

    for (uint16_t i = 0; i < N; ++i) 
    {
        char path[CONSTANTS::PATH_SIZE];
        file.getline(path, CONSTANTS::PATH_SIZE, CONSTANTS::TERMINATING_NULL);
        functions[i] = loadFunction(path);
    }
    return new MinimumOfPartialFunctions(functions, N);
}