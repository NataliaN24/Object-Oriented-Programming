#include"Time.h"
#include<iostream>

Time::Time(unsigned h, unsigned m, unsigned s) 
{
    setHours(h);
    setMinutes(m);
    setSeconds(s);
}

unsigned Time:: getHours() const
{ 
    return hours;
}

unsigned Time::getMinutes() const
{ 
    return minutes;
}

unsigned Time::getSeconds() const
{ 
    return seconds; 
}

void Time::setHours(unsigned h) 
{
    if (h <= CONSTANTS_TIME::HOURS)
    {
        hours = h;
    }
    else
    {
        std::cerr << "Error: Invalid value for hours." << std::endl;
    }
}

void Time::setMinutes(unsigned m)
{
    if (m <= CONSTANTS_TIME::MINUTES_OR_SEC)
    {
        minutes = m;
    }
    else 
    {
        std::cerr << "Error: Invalid value for minutes." << std::endl;
    }
}

void Time::setSeconds(unsigned s) 
{
    if (s <= CONSTANTS_TIME::MINUTES_OR_SEC)
    {
        seconds = s;
    }
    else 
    {
        std::cerr << "Error: Invalid value for seconds." << std::endl;
    }
}

unsigned Time::toSeconds() const
{
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::printTime() const 
{
    if (hours < 10)
    {
        std::cout << "0" << hours << ":";
    }
    else
    {
        std::cout << hours << ":";
    }

    if (minutes < 10) 
    {
        std::cout << "0" << minutes << ":";
    }
    else {
        std::cout << minutes << ":";
    }

    if (seconds < 10)
    {
        std::cout << "0" << seconds << ". ";
    }
    else 
    {
        std::cout << seconds << ". ";
    }
}
