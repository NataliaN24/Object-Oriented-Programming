#include<iostream>
#include"kPriorityQueue.hpp"

int main()
{
    try 
    {
        kPriorityQueue<char> q(4); 

        q.push('A', 0); 
        q.push('B', 3);
        q.push('C', 2);
        q.push('D', 2); 
        q.push('E', 1); 

        std::cout << q.peek() << std::endl; 
        q.pop();

        std::cout << q.peek() << std::endl; 
        q.pop();

        std::cout << q.peek() << std::endl; 
        q.pop();

        std::cout << q.peek() << std::endl; 
        q.pop();

        std::cout << q.peek() << std::endl; 
        q.pop();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cout << "Unknown exception occurred." << std::endl;
    }

    return 0;
}