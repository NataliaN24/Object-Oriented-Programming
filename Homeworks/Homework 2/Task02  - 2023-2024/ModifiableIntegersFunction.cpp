#include "ModifiableIntegersFunction.h"

void ModifiableIntegersFunction::copyFrom(const ModifiableIntegersFunction& other)
{
    func = other.func;
    if (other.excludingPoints != nullptr)
    {
        excludingPoints = new bool[CONSTANTS::MAX_SIZE + 1];
        for (int i = 0; i <= CONSTANTS::MAX_SIZE; ++i)
        {
            excludingPoints[i] = other.excludingPoints[i];
        }
    }
    else 
    {
        excludingPoints = nullptr;
    }

    if (other.specificOutput != nullptr)
    {
        specificOutput = new int16_t[CONSTANTS::MAX_SIZE + 1];
        for (int i = 0; i < CONSTANTS::MAX_SIZE; ++i) 
        {
            specificOutput[i] = other.specificOutput[i];
        }
    }
    else 
    {
        specificOutput = nullptr;
    }

}

void ModifiableIntegersFunction::moveFrom(ModifiableIntegersFunction&& other) noexcept
{
    func = other.func;
    other.func = nullptr;

    excludingPoints = other.excludingPoints;
    other.excludingPoints = nullptr;

    specificOutput = other.specificOutput;
    other.specificOutput = nullptr;
}

void ModifiableIntegersFunction::free()
{
   
    if (excludingPoints != nullptr) 
    {
        delete[] excludingPoints;
        excludingPoints = nullptr;
    }
    if (specificOutput != nullptr)
    {
        delete[] specificOutput;
        specificOutput = nullptr;
    }
    func = nullptr;
}

ModifiableIntegersFunction::ModifiableIntegersFunction():func(nullptr), excludingPoints(nullptr), specificOutput(nullptr) 
{
}

ModifiableIntegersFunction::ModifiableIntegersFunction(const ModifiableIntegersFunction& other)
{
    copyFrom(other);
}

ModifiableIntegersFunction::ModifiableIntegersFunction(ModifiableIntegersFunction&& other)noexcept
{
    moveFrom(std::move(other));
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(const ModifiableIntegersFunction& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(ModifiableIntegersFunction&& other)noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t(*function)(int16_t)): func(function)
{
    excludingPoints = new bool[CONSTANTS::MAX_SIZE + 1]();
    specificOutput = new int16_t[CONSTANTS::MAX_SIZE + 1]();
}

ModifiableIntegersFunction::~ModifiableIntegersFunction()
{
    free();
}

void ModifiableIntegersFunction::setOutputForSpecificInput(int16_t input, int16_t output)
{
    if (input >= CONSTANTS::MIN_16_VALUE && input <= CONSTANTS::MAX_16_VALUE)
    {
        specificOutput[input - CONSTANTS:: MIN_16_VALUE] = output;
    }
    else
    {
        throw std::out_of_range("Input out of range");
    }
}

void ModifiableIntegersFunction::exclusion(int16_t input)
{
    if (input >= CONSTANTS::MIN_16_VALUE && input <= CONSTANTS::MAX_16_VALUE) 
    {
        excludingPoints[input - CONSTANTS::MIN_16_VALUE] = true;
    }
    else 
    {
        throw std::out_of_range("Input out of range");
    }
}

int16_t ModifiableIntegersFunction::operator()(int16_t input)const
{
    if (func == nullptr)
    {
        throw std::runtime_error("Function not set");
    }

    if (input >= CONSTANTS::MIN_16_VALUE && input <= CONSTANTS::MAX_16_VALUE) 
    {
        if (excludingPoints[input - CONSTANTS::MIN_16_VALUE])
        {
            throw std::runtime_error("Input value excluded");
        }

        if (specificOutput[input - CONSTANTS::MIN_16_VALUE] != 0) 
        {
            return specificOutput[input - CONSTANTS::MIN_16_VALUE];
        }
    }

    return func(input);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other)
{
    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i)
    {
        if (!excludingPoints[i - CONSTANTS::MIN_16_VALUE] && !other.excludingPoints[i - CONSTANTS::MIN_16_VALUE])
        {
            if (specificOutput[i - CONSTANTS::MIN_16_VALUE] && other.specificOutput[i - CONSTANTS::MIN_16_VALUE] )
            {
                specificOutput[i - CONSTANTS::MIN_16_VALUE] += other.specificOutput[i - CONSTANTS::MIN_16_VALUE];
            }
            else {
                excludingPoints[i - CONSTANTS::MIN_16_VALUE] = true;
            }
        }
        else 
        {
            excludingPoints[i - CONSTANTS::MIN_16_VALUE] = true;
        }
    }
    return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other)
{
    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i)
    {
        if (!excludingPoints[i - CONSTANTS::MIN_16_VALUE] && !other.excludingPoints[i - CONSTANTS::MIN_16_VALUE])
        {
            if (specificOutput[i - CONSTANTS::MIN_16_VALUE] && other.specificOutput[i - CONSTANTS::MIN_16_VALUE])
            {
                specificOutput[i - CONSTANTS::MIN_16_VALUE] -= other.specificOutput[i - CONSTANTS::MIN_16_VALUE];
            }
            else {
                excludingPoints[i - CONSTANTS::MIN_16_VALUE] = true;
            }
        }
        else
        {
            excludingPoints[i - CONSTANTS::MIN_16_VALUE] = true;
        }
    }
    return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator*=(const ModifiableIntegersFunction& other)
{ 
    if (func == nullptr || other.func == nullptr)
    {
        throw std::runtime_error("One of the functions is not set.");
    }

    
    int16_t* newSpecificOutput = new int16_t[CONSTANTS::MAX_SIZE + 1]();
    bool* newExcludingPoints = new bool[CONSTANTS::MAX_SIZE + 1]();

    for (int i = 0; i <= CONSTANTS::MAX_SIZE; ++i) {
        newSpecificOutput[i] = specificOutput[i] * other.specificOutput[i];
    }

    for (int i = 0; i <= CONSTANTS::MAX_SIZE; ++i) {
        newExcludingPoints[i] = excludingPoints[i] || other.excludingPoints[i];
    }

   
    delete[] specificOutput;
    delete[] excludingPoints;

    specificOutput = newSpecificOutput;
    excludingPoints = newExcludingPoints;

  
    return *this;
}

ModifiableIntegersFunction ModifiableIntegersFunction::operator^(int k) 
{
    if (k == 0) 
    {
        return ModifiableIntegersFunction([](int16_t x) { return x; });
    }
    else 
    {
        return *this *= (*this ^ (k - 1));
    }
}

bool ModifiableIntegersFunction::operator<(const ModifiableIntegersFunction& other)const 
{

    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i)
    {
        bool thisDefined = !excludingPoints[i - CONSTANTS::MIN_16_VALUE];
        bool otherDefined = !other.excludingPoints[i - CONSTANTS::MIN_16_VALUE];


        if (thisDefined && otherDefined)
        {
            int16_t thisOutput = specificOutput[i - CONSTANTS::MIN_16_VALUE];
            int16_t otherOutput = other.specificOutput[i - CONSTANTS::MIN_16_VALUE];
            if (thisOutput != otherOutput) 
            {
                return thisOutput < otherOutput;
            }
        }

        else if (thisDefined) 
        {
            return false;
        }
        else if (otherDefined) 
        {
            return true;
        }
    }
    return false;
   
}

bool ModifiableIntegersFunction::operator>(const ModifiableIntegersFunction& other) const
{
    return other < *this;
}

bool ModifiableIntegersFunction::operator<=(const ModifiableIntegersFunction& other) const
{
    return !(other < *this);
}

bool ModifiableIntegersFunction::operator>=(const ModifiableIntegersFunction& other) const
{
    return !(*this < other);
}

bool ModifiableIntegersFunction::operator==(const ModifiableIntegersFunction& other) const
{
    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i) 
    {
        bool thisDefined = !excludingPoints[i - CONSTANTS::MIN_16_VALUE];
        bool otherDefined = !other.excludingPoints[i - CONSTANTS::MIN_16_VALUE];


        if (thisDefined && otherDefined) 
        {
            if (specificOutput[i - CONSTANTS::MIN_16_VALUE] != other.specificOutput[i - CONSTANTS::MIN_16_VALUE])
            {
                return false;
            }
        }

        else if (thisDefined || otherDefined) 
        {
            return false;
        }
    }
    return true;
}

bool ModifiableIntegersFunction::operator!=(const ModifiableIntegersFunction& other) const
{
    return !(*this == other);
}

bool ModifiableIntegersFunction::isInjective() const
{
    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i)
    {
        int16_t output = func(i);

        for (int j = CONSTANTS::MIN_16_VALUE; j <= CONSTANTS::MAX_16_VALUE; ++j)
        {
            if (j != i)
            {
                int16_t other_output = func(j);
                if (output == other_output) 
                {

                    return false;
                }
            }
        }
    }
    return true;
}

bool ModifiableIntegersFunction::isSurjective() const
{
    for (int i = CONSTANTS::MIN_16_VALUE; i <= CONSTANTS::MAX_16_VALUE; ++i) 
    {
            int16_t output = func(i);
            bool found = false;
            for (int j = CONSTANTS::MIN_16_VALUE; j <= CONSTANTS::MAX_16_VALUE; ++j) 
            {
                if (output == j)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                return false;
            }
       
    }
    return true;
}

bool ModifiableIntegersFunction::isBijective() const
{
    return isInjective() && isSurjective();
}

bool areGraphsParallel(const ModifiableIntegersFunction& f1, const ModifiableIntegersFunction& f2)
{
    int16_t input1 = NUMBERS::ZERO;        //the idea here is to choose some input values where we want to compare the outputs                    
    int16_t input2 = NUMBERS::ONE;

    int16_t output1 = f1(input1);  //then we calculate the ouput values or both functions at the chosen input values
    int16_t output2 = f2(input2);

 
    int16_t difference = output2 - output1;

    for (int input = CONSTANTS::MIN_16_VALUE; input <= CONSTANTS::MAX_16_VALUE; ++input)   //here we check if the difference remains constant for different input values 
    { 
        if (f1(input) + difference != f2(input))                                           //if the difference is not constant graphs are not parallel
        {
            return false;
        }
    }
    return true;
}

void ModifiableIntegersFunction::plot(double x1, double x2, double y1, double y2) const
{
    for (double x = x1; x <= x2; ++x) 
    {
        
        if (x >= y1 && x <= y2)
        {
        
            int16_t y = func((int16_t)x);
            
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
    }
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs)
{
    ModifiableIntegersFunction result(lhs);
    result += rhs;
    return result;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) 
{
    ModifiableIntegersFunction result(lhs);
    result -= rhs;
    return result;
}

ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) 
{
    ModifiableIntegersFunction result(lhs);
    result *= rhs;
    return result;
}