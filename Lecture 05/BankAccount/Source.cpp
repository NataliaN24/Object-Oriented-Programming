#include <iostream>
#include <fstream>
#include "BankAccount.h"

int main() {
    
    BankAccount account1("John Doe", "1234567890", 1000.50);
    BankAccount account2("Jane Smith", "9876543210");

    account1.deposit(500.75);
    account2.deposit(300);
    account1.draw(200);

    std::cout << "Account 1: " << account1.getName() << " "
        << account1.getBankNumber() << " "
        << account1.getHowMuchMoneyInBank() << std::endl;

    std::cout << "Account 2: " << account2.getName() << " "
        << account2.getBankNumber() << " "
        << account2.getHowMuchMoneyInBank() << std::endl;

    return 0;
}
