#include "Bank.h"

void Bank::resize(unsigned int newCapacity)
{
    BankAccount* copyAccount = new BankAccount[newCapacity];
    for (int i = 0; i < count; i++)
    {
        copyAccount[i] = accounts[i];
    }
    delete[]accounts;
    accounts = copyAccount;
    capacity = newCapacity;
}

void Bank::free()
{
    delete[]accounts;
    count = capacity = 0;
}

void Bank::copyFrom(const Bank& other)
{
    accounts = new BankAccount[other.capacity];
    for (int i = 0; i < other.count; ++i)
    {
        accounts[i] = other.accounts[i];
    }
    count = other.count;
}

Bank::Bank()
{
    accounts = new BankAccount[MAX_CAPACITY];
    count = 0;
    capacity = MAX_CAPACITY;
}

Bank::Bank(const Bank& other)
{
    copyFrom(other);
}

Bank& Bank::operator=(const Bank& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Bank::~Bank()
{
    free();
}

Bank::Bank(const BankAccount* accounts, unsigned int capacity, unsigned int count)
{
    this->capacity = capacity;
    this->accounts = new BankAccount[capacity];
    this->count = count;
    for (int i = 0; i < count; i++)
    {
        this->accounts[i] = accounts[i];
    }
}

void Bank::addAccount(const BankAccount& account)
{
    if (count < capacity)
    {
        accounts[count++] = account;
    }
    else
    {
        resize(capacity * 2);
        accounts[count++] = account;
    }
}

bool Bank::existsAccount(const char* bankNumber)
{
    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bankNumber, accounts[i].getBankNumber()) == 0)
        {
            return true;
        }
    }
    return false;
}

void Bank::removeAccount(const char* bankNumber)
{
    int index = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(bankNumber, accounts[i].getBankNumber()) == 0)
        {
            index = i;
            break;
        }
    }
    std::swap(accounts[index], accounts[count]);
    count--;

}

double Bank::getMoney(const char* bankNumber)
{

    for (int i = 0; i < count; i++)
    {
        if (strcmp(bankNumber, accounts[i].getBankNumber()) == 0)
        {
            return accounts[i].getHowMuchMoneyInBank();
        }
    }
}

double Bank::getMoneyFromAllAccountsOfAClient(const char* name)
{
    double sum = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(name, accounts[i].getName()) == 0)
        {
            sum += accounts[i].getHowMuchMoneyInBank();
        }
    }
    return sum;
}

void Bank::saveInformation(std::ofstream& ofs)
{
    if (!ofs.is_open())
    {
        std::cerr << "error opening the file!";
    }
    ofs << capacity << " " << count;
    for (int i = 0; i < count; i++)
    {
         accounts[i].print(ofs);
    }
}