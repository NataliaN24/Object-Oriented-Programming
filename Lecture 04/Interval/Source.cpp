#include <iostream>
#include "Interval.h"

int main() 
{
    Interval interval1(5, 15);
    Interval interval2(10, 20);

    std::cout << "Interval 1: [" << interval1.getA() << ", " << interval1.getB() << "]" << std::endl;
    std::cout << "Interval 2: [" << interval2.getA() << ", " << interval2.getB() << "]" << std::endl;

    int num = 12;
    std::cout << num << " is in Interval 1: " << (interval1.isInInterval(num) ? "Yes" : "No") << std::endl;

    std::cout << "Primes in Interval 1: " << interval1.getPrimesCount() << std::endl;
    std::cout << "Palindromes in Interval 1: " << interval1.getPalindromesCount() << std::endl;

    std::cout << "Interval 1 is subinterval of Interval 2: " << (interval1.isSubinterval(interval2) ? "Yes" : "No") << std::endl;

    try
    {
        Interval intersec = intersection(interval1, interval2);
        std::cout << "Intersection of Interval 1 and Interval 2: [" << intersec.getA() << ", " << intersec.getB() << "]" << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}