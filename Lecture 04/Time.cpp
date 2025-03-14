#include <iostream>
#include <cstring>
#include<fstream>
#include <iomanip>
using namespace std;
#pragma warning(disable:4996)

constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;
constexpr unsigned LOWER_DINNER_HOUR = 20;
constexpr unsigned LOWER_DINNER_MIN = 30;
constexpr unsigned UPPER_DINNER_HOUR = 22;
constexpr unsigned LOWER_PARTY_HOUR = 23;
constexpr unsigned UPPER_PARTY_HOUR = 6;

//Реализирайте клас Time, който ще се използва за работа с часове(13:05 : 45).Вашият клас трябва да има следния интерфейс :
//
//Подразбиращ се контруктор, който създава часа на 00 : 00 : 00.
//Конструктор, който приема три параметъра - час, минути и секунди.
//Член - функция, която връща оставащото време до полунощ.
//Член - функция, която увеличава часа с 1 секунда.
//Член - функция, която връща дали е време за вечеря.В рамките на задачата време за вечеря е между 20 : 30 и 22 : 00.
//Член - функция, която връща дали е време за парти.В рамките на задачата време за парти е между 23 : 00 и 06 : 00.
//Член - функция, която приема друг обект от тип Time и връща обект от тип Time, което е разликата между двете времена.
//Член - функция, която която приема друг обект от тип Time и сравнява двата обекта(по - къснен / по - ранен)
//Член - функция за принтиране на часа.
//Да се направи масив от 10 времена и да се сортира стабилно с някоя от изучаваните сортировки.

class Time
{
	unsigned secFromMidnight;
	bool validateANDset(unsigned lowerBound, unsigned upperBound, unsigned newValue, unsigned oldValue, unsigned multiplier)
	{
		if (newValue >= lowerBound && newValue <= upperBound)
		{
			(secFromMidnight -= (oldValue * multiplier)) += (newValue * multiplier);
			return true;
		}
		else
		{
			return false;
		}

	}
public:
	Time() :secFromMidnight(0)
	{

	}
	Time(unsigned hours, unsigned min, unsigned sec)
	{
		setHours(hours);
		setMins(min);
		setSeconds(sec);
	}
	unsigned getHoursTillMidnight()const
	{
		return secFromMidnight / SECONDS_IN_HOURS;
	}
	unsigned getMinsTillMidnight()const
	{
		return (secFromMidnight / 60) % 60;
	}
	unsigned getSecondsTillMidnight()const
	{
		return secFromMidnight % 60;
	}
	bool setHours(unsigned hours)
	{
		return validateANDset(0, 23,hours, getHoursTillMidnight(), SECONDS_IN_HOURS);
	}
	bool setMins(unsigned min)
	{
		return validateANDset(0, 59, min, getMinsTillMidnight(), SECONDS_IN_MINUTE);
	}
	bool setSeconds(unsigned sec)
	{
		return validateANDset(0, 59, sec, getSecondsTillMidnight(), 1);
	}
	void tick()
	{
		++secFromMidnight %= DAY_SECONDS;
	}
	void serialize(std::ostream& os) const
	{
		os << setw(2) << setfill('0') << getHoursTillMidnight() << ":"
			<< setw(2) << setfill('0') << getMinsTillMidnight() << ":"
			<< setw(2) << setfill('0') << getSecondsTillMidnight() << std::endl;
	}
	bool isDinnerTime()const
	{
		unsigned hours = getHoursTillMidnight();
		unsigned min = getMinsTillMidnight();
		if ((hours > LOWER_DINNER_HOUR || (hours == LOWER_DINNER_HOUR && min >= LOWER_DINNER_MIN)) &&
			(hours < UPPER_DINNER_HOUR || (hours == UPPER_DINNER_HOUR && min == 0)))
		{
			return true;
		}
		return false;
	}
	bool isPartyTime()const
	{
		unsigned hours = getHoursTillMidnight();
		unsigned min = getMinsTillMidnight();
		if ((hours >= LOWER_PARTY_HOUR && min >= 0)) {
			return true;
		}
		else if (hours >= 0 && hours<UPPER_PARTY_HOUR && min >= 0) {
			return  true;
		}
		else if (hours == UPPER_PARTY_HOUR && min == 0)
		{
			return true;
		}
		
		return false;
	}
	Time difference(const Time& other) const {
		unsigned differenceInSec;
		if (secFromMidnight > other.secFromMidnight) {
			differenceInSec = secFromMidnight - other.secFromMidnight;
		}
		else {
			differenceInSec = other.secFromMidnight - secFromMidnight;
		}
		return Time(differenceInSec / SECONDS_IN_HOURS, (differenceInSec / SECONDS_IN_MINUTE) % 60, differenceInSec % 60);
	}

	bool isEarlierThan(const Time& other)const
	{
		return secFromMidnight < other.secFromMidnight;
	}
	void print()const
	{
		std::cout << getHoursTillMidnight() << " " << getMinsTillMidnight() << " " << getSecondsTillMidnight() << endl;
	}

};

int main() {

	Time t1(6, 0, 0);
	cout << "Initial Time: ";
	t1.print();  


	Time dinnerTime(20, 30, 0);
	cout << "Dinner Time (20:30:00): " << (dinnerTime.isDinnerTime() ? "Yes" : "No") << endl;  

	
	Time partyTime1(23, 0, 0);
	cout << "Party Time (23:00:00): " << (partyTime1.isPartyTime() ? "Yes" : "No") << endl;  
	Time partyTime2(5, 0, 0);
	cout << "Party Time (05:00:00): " << (partyTime2.isPartyTime() ? "Yes" : "No") << endl;  
	Time nonPartyTime(7, 0, 0);
	cout << "Non-Party Time (07:00:00): " << (nonPartyTime.isPartyTime() ? "Yes" : "No") << endl;  

	Time t2(8, 45, 30);
	Time diff = t1.difference(t2);
	cout << "Difference between ";
	t1.print();
	cout << "and ";
	t2.print();
	cout << "is ";
	diff.print(); 

	cout << "Is t1 earlier than t2? " << (t1.isEarlierThan(t2) ? "Yes" : "No") << endl;  

	return 0;
}
