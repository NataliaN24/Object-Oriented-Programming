#pragma once
#include<iostream>
#include"fstream"
#pragma once

namespace GLOBAL_CONSTANTS 
{
    constexpr int MAX_NAME_LENGTH = 64;
    constexpr int MAX_CONTENT_LENGTH = 256;
    constexpr char MAX_SONGS = 30;
}

namespace CONSTANTS_TIME
{
    constexpr unsigned HOURS = 23;
    constexpr unsigned MINUTES_OR_SEC = 59;
}

namespace CONSTANTS_BITS 
{
    constexpr int BITS = 8;
}

enum class Genre : unsigned char
{
    rock = 1 << 0, 
    pop = 1 << 1,
    hip_hop = 1 << 2, 
    electronic = 1 << 3, 
    jazz = 1 << 4,
    unknown = 0
};

size_t getFileSize(std::ifstream& f);

enum class sortByCriteria
{
    sortByName,
    sortByDuration
};