#include "BankAccount.h"

BankAccount::BankAccount(const char* name, const char* number, double sum)
{
	setName(name);
	setNumber(number);
	setMoney(sum);
}

BankAccount::BankAccount(const char* name, const char* number)
{
	setName(name);
	setNumber(number);
	setMoney(0);
}

BankAccount::BankAccount()
{
	std::strcpy(name, " ");
	std::strcpy(bankAccout, " ");
	moneyInBank = 0;
}

void BankAccount::setName(const char* name)
{
	if (strlen(name) < NAME_LENGTH)
	{
		strcpy(this->name, name);
	}
}

void BankAccount::setNumber(const char* number)
{
	if (strlen(number) < BANK_ACC)
	{
		strcpy(bankAccout, number);
	}
}

void BankAccount::setMoney(double money)
{
	moneyInBank = money;
}

const char* BankAccount::getName() const
{
	return name;
}

const char* BankAccount::getBankNumber() const
{
	return bankAccout;
}

double BankAccount::getHowMuchMoneyInBank() const
{
	return moneyInBank;
}

void BankAccount::deposit(unsigned int money)
{
	moneyInBank += money;
}

void BankAccount::draw(unsigned int money)
{
	moneyInBank -= money;
}

void BankAccount::print(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		std::cerr << "error opening the file!";
	}
	ofs << name << " " << bankAccout << " " << moneyInBank;
}
