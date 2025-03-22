#pragma once
#include"BankAccount.h"

constexpr unsigned int MAX_CAPACITY = 1000;
class Bank
{
	BankAccount* accounts;
	unsigned int capacity;
	unsigned int count;

	void resize(unsigned int newCapacity);
	void free();
	void copyFrom(const Bank& other);
public:
	Bank();
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	~Bank();
	Bank(const BankAccount* accounts,unsigned int capacity, unsigned int count);
	void addAccount(const BankAccount& account);
	bool existsAccount(const char* bankNumber);
	void removeAccount(const char*bankNumber);
	double getMoney(const char* bankNumber);
	double getMoneyFromAllAccountsOfAClient(const char* name);
	void saveInformation(std::ofstream& ofs);

};