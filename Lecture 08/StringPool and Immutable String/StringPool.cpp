#include "StringPool.h"
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)

StringPool::StringPool()
{
    stringCapacity = 8;
    stringCount = 0;
    strRecords = new StringRecord[stringCapacity];
}

const char* StringPool::getAllocatedString(const char* str)
{
    int index = findAllocatedString(str);
    if (index != -1) 
    {
        strRecords[index].refCount++;
        std::cout << "String found in cache, ref count: " << strRecords[index].refCount << std::endl;
        return strRecords[index].str;
    }
    else
    {
        std::cout << "String NOT found in cache. Allocating.." << std::endl;
        unsigned index = allocatedString(str);
        strRecords[index].refCount++;
        return strRecords[index].str;
    }
}

void StringPool::releaseString(const char* str)
{
    int index = findAllocatedString(str);
    strRecords[index].refCount--;
    if (strRecords[index].refCount == 0)
    {
        std::cout << "Removing record: " << strRecords[index].str << " (No more refs)" << std::endl;
        removeRecord(index);
    }
}

StringPool::~StringPool()
{
    for (unsigned  i = 0; i > stringCapacity; i++)
    {
        delete[]strRecords[i].str;
    }
    delete[]strRecords;
}

void StringPool::removeRecord(unsigned index)
{
    std::swap(strRecords[index], strRecords[stringCount - 1]);
    delete[]strRecords[stringCount - 1].str;
    strRecords[stringCount - 1].str = nullptr;
    strRecords[stringCount - 1].refCount = 0;
    stringCount--;
}

void StringPool::resize(unsigned newCap)
{
    StringRecord* newStr = new StringRecord[newCap];
    for (unsigned i = 0; i < stringCount; ++i)
    {
        newStr[i] = strRecords[i];
    }
    stringCapacity = newCap;
    delete[]strRecords;
    strRecords = newStr;
}

int StringPool::findAllocatedString(const char* str) const
{
    for (int i = 0; i < stringCount; i++)
    {
        if (strcmp(str, strRecords[i].str) == 0)
        {
            return i;
        }
    }
    return -1;
}

unsigned StringPool::allocatedString(const char* str)
{
    if (stringCount == stringCapacity)
    {
        resize(stringCapacity * 2);
    }
    unsigned firstFreeIndex = stringCount++;
    strRecords[firstFreeIndex].str = new char[strlen(str) + 1];
    strcpy(strRecords[firstFreeIndex].str, str);
    strRecords[firstFreeIndex].refCount = 0;
    return firstFreeIndex;
}