#include "FunctionUtilites.h"

namespace CONSTANTS_FOR_UTILIES
{
    constexpr size_t EXIT_LENGTH = 5;
    constexpr char EXIT[5] = "exit";
}

FunctionUtilities ::FunctionUtilities(PartialFunction* func) : func(func)
{
}

void FunctionUtilities::mode1()
{
    int32_t a, b;
    std::cout << "Enter two integers a and b (a <= b): ";
    std::cin >> a >> b;
    if ( a > b) 
    {
        throw std::logic_error("Error: a is greater than b!");
    }

    for (int32_t x = a; x <= b; ++x) 
    {
        if (func->IsDefinedAtPoint(x))
        {
            try 
            {
                std::cout << "f(" << x << ") = " << func->calculateTheResult(x) << "   ";
            }
            catch (const std::out_of_range& e)
            {
                std::cerr << e.what() << std::endl;
            }
            catch (...)
            {
                std::cerr << "Error catched." << std::endl;
            }
        }
        else 
        {
            throw("f of x is not defined");
        }
    }
    std::cout << std::endl;
}


void FunctionUtilities::mode2()
{
    int32_t x;
    char input[CONSTANTS_FOR_UTILIES::EXIT_LENGTH];

    while (true)
    {
        std::cout << "Enter a number or type 'exit' to quit: ";

        if (!(std::cin >> x)) 
        {
            std::cin >> input; 
            if (std::strcmp(input, CONSTANTS_FOR_UTILIES::EXIT) == 0) break;
            else
            {
                std::cerr << "Invalid input. Please enter a number or 'exit' to quit." << std::endl;
                continue;
            }
        }

        if (func->IsDefinedAtPoint(x))
        {
            try 
            {
                std::cout << "Result at " << x << ": " << func->calculateTheResult(x) << std::endl;
            }

            catch (const std::out_of_range& e)
            {
                std::cerr << e.what() << std::endl;
            }
            catch (...) 
            {
                std::cerr << "Error catched." << std::endl;
            }
        }
        else 
        {
            throw("f of x is not defined");
        }
    }
}

void FunctionUtilities::copyFrom(const FunctionUtilities& other)
{
    func = other.func;
}

void FunctionUtilities::moveFrom(FunctionUtilities&& other) noexcept
{
    func = other.func;
    other.func = nullptr;
}

void FunctionUtilities::free()
{
    delete[]func;
}

FunctionUtilities::FunctionUtilities():func(nullptr)
{
}

FunctionUtilities::FunctionUtilities(const FunctionUtilities& other)
{
    copyFrom(other);
}

FunctionUtilities::FunctionUtilities(FunctionUtilities&& other) noexcept
{
    moveFrom(std::move(other));
}

FunctionUtilities& FunctionUtilities::operator=(const FunctionUtilities& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

FunctionUtilities& FunctionUtilities::operator=(FunctionUtilities&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

FunctionUtilities::~FunctionUtilities()
{
    free();
}
