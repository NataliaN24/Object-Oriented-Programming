#include <iostream>
#include <stdexcept>
#include"MyString.h"

//1. Реализирайте клас Ticket, който описва билет за театрална постановка.Всеки билет има име на постановката от тип MyString и цена от тип double.
//Направете подходящи конструктори.
//Реализирайте клас Student Ticket, който е 2 пъти по - евтин.В конструктора си приема име и оригинална цена за постановката.Реализирайте 
//клас Group Ticket, който е с 20 % по - евтин от нормалния.Направете подходящи функции за принтиране на информацията за билетите.

class Ticket
{
	MyString name;
	double price;

public:

	Ticket(const MyString&name,double price):name(name),price(price){}

	Ticket() = default;

	double getPrice()const
	{
		return price;
	}
	const MyString& getName()const
	{
		return name;
	}
	void print()const
	{
		std::cout << name.c_str() << " " << price << "$" << std::endl;
	}
};

class StudentTicket:public Ticket 
{
public:
	StudentTicket(const MyString& name, double price) :Ticket(name, price / 2){}
};

class GroupTicket :public Ticket
{
public:
	GroupTicket(const MyString&name,double price):Ticket(name,price-0.2*price){}
};

int main()
{
	MyString playName("Hamlet");

	Ticket regularTicket(playName, 100.0);
	StudentTicket studentTicket(playName, 100.0);
	GroupTicket groupTicket(playName, 100.0);

	regularTicket.print();
	studentTicket.print();
	groupTicket.print();

	return 0;
}
