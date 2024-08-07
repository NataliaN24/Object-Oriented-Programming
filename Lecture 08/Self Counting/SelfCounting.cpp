#include "SelfCounting.h"
unsigned SelfCounting::liveObjCount = 0;
unsigned SelfCounting::createdCount = 0;

SelfCounting::SelfCounting():SelfCounting(42)
{
}

SelfCounting::SelfCounting(int value):constValue(value)
{
    liveObjCount++;
    createdCount++;
}

SelfCounting::SelfCounting(const SelfCounting& other):constValue(other.constValue)
{
    liveObjCount++;
    createdCount++;
}

SelfCounting::~SelfCounting()
{
    liveObjCount--;
}

unsigned SelfCounting::getLiveObjCout()
{
    return liveObjCount;
}

unsigned SelfCounting::getCreatedCount()
{
    return createdCount;
}
