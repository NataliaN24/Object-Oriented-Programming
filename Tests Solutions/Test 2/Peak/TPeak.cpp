#include "TPeak.h"

void TPeak::copyFrom(const TPeak& other)
{
    if (other.nameTPeak) {
        this->nameTPeak = new char[strlen(other.nameTPeak) + 1];
        strcpy(this->nameTPeak, other.nameTPeak);
    }
   
}

void TPeak::free()
{
    delete[]nameTPeak;
}

TPeak::TPeak()
{
    nameTPeak = new char[1];
    nameTPeak[0] = '\0';
}

TPeak::TPeak(const char* mountainName, double h, const char* peakName):
    Peak(mountainName,h)
{
    setName(peakName);
}

TPeak::TPeak(const TPeak& other):Peak(other)
{
    copyFrom(other);
}

TPeak& TPeak::operator=(const TPeak& other)
{

    if (this != &other)
    {
        free();
        copyFrom(other);
        Peak::operator=(other);
    }
    return *this;
}

TPeak::~TPeak()
{
    free();
}

void TPeak::setPeakName(const char* newName)
{
    if (this->nameTPeak)
    {
        delete[]nameTPeak;

    }
    nameTPeak = new char[strlen(newName) + 1];
    strcpy(this->nameTPeak, newName);
}

const char* TPeak::getPeakName() const
{
    return nameTPeak;
}

void TPeak::printPeakName() const
{
    std::cout << "Tpeak";
}

Peak* TPeak::clone() const
{
    return new TPeak(*this);
}

bool TPeak::twoPeaksNear(const Peak* other) const
{
    return  other->nearTPeak(this);
}

bool TPeak::nearMpeak(const MPeak* mpeak) const
{
    std::cout << "near Mpeak";
    return true;
}

bool TPeak::nearTPeak(const TPeak* tpeak) const
{
    std::cout << "near tpeak";
    return true;
}

