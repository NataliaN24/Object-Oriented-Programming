#pragma once
#include<iostream>
#include<fstream>
#pragma warning(disable:4996)

constexpr int NAME_LENGTH = 15;
constexpr int BANK_ACC = 30;

class BankAccount
{
	char name[NAME_LENGTH + 1];
	char bankAccout[BANK_ACC + 1];
	double moneyInBank;
public:
	BankAccount(const char* name, const char* number, double money);
	BankAccount(const char* name, const char* number);
	BankAccount();

	void setName(const char* name);
	void setNumber(const char* number);
	void setMoney(double money);
	const char* getName()const;
	const char* getBankNumber()const;
	double getHowMuchMoneyInBank()const;


	void deposit(unsigned int money);
	void draw(unsigned int money);

	void print(std::ofstream& ofs);
};

