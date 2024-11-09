#include<iostream>
#include"Computer.h"
#include"GamingConsole.h"
#include"Laptop.h"
#include"PC.h"

int main() {
    PC myPC("NVIDIA GTX 1080", 500, 16, 3.4);
    Laptop myLaptop("Intel HD Graphics", 65, 8, 2.5);
    GamingConsole myConsole("AMD Radeon", 150, 4, 1.8);

    std::cout << "PC Details:\n";
    myPC.computer_TYPE();
    myPC.computer_PERIPHERALS();
    std::cout << "\n";

    std::cout << "Laptop Details:\n";
    myLaptop.computer_TYPE();
    myLaptop.computer_PERIPHERALS();
    std::cout << "\n";

    std::cout << "Gaming Console Details:\n";
    myConsole.computer_TYPE();
    myConsole.computer_PERIPHERALS();
    std::cout << "\n";

    return 0;
}
