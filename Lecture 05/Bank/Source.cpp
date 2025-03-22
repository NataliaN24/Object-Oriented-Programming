#include <iostream>
#include <fstream>
#include "BankAccount.h"
#include "Bank.h"

int main() {
    // Create some bank account objects
    BankAccount account1("John Doe", "1234567890", 1000.50);
    BankAccount account2("Jane Smith", "9876543210", 3000.75);
    BankAccount account3("Alice Johnson", "1122334455", 1500.30);

    // Create a Bank object
    Bank bank;

    // Add accounts to the bank
    bank.addAccount(account1);
    bank.addAccount(account2);
    bank.addAccount(account3);

    std::cout << "Money in John Doe's account: " << bank.getMoney("1234567890") << std::endl;

    std::cout << "Total money for Jane Smith: " << bank.getMoneyFromAllAccountsOfAClient("Jane Smith") << std::endl;

    bank.removeAccount("9876543210");
    std::cout << "After removing Jane Smith's account." << std::endl;
    std::cout << "Money in Jane Smith's account: " << bank.getMoney("9876543210") << std::endl;

    std::ofstream ofs("bank_info.txt");
    if (ofs.is_open()) {
        bank.saveInformation(ofs);
    }
    else {
        std::cerr << "Error opening the file!" << std::endl;
    }

    ofs.close(); 

    return 0;
}
