﻿#pragma once
#include<climits>
#include <algorithm>
#include <cmath>

class Interval
{
	int a = INT_MIN;
	int b = INT_MAX;

public:
	Interval();
	Interval(int a, int b);

	void setA(int a);
	void setB(int b);

	int getA()const;
	int getB()const;

	bool isInInterval(int x)const;
	unsigned getCountCondition(bool(*pred)(int))const;
	unsigned getPrimesCount()const;
	unsigned getPalindromesCount()const;
	bool isSubinterval(const Interval& other)const;
};
Interval intersection(const Interval& lhs,const Interval& rhs);


задача 1: Реализирайте клас / структура интервал, който представлява интервал[a, b](задължително а <= b) от реалната права.
Нашият интервал ще бъде дискретен - началото и краят му ще бъдат цели числа и ще разглеждаме само точки, които са цели числа.
Релизирайте следният интерфейс :

Подразбиращ се контруктор, който създава интервала[0, 0].
Конструктор, който приема двата параметъра.Ако a <= b, то създава интервала[a, b].В противен случай, създава[0, 0].
Член - функция, която връща дължината на интервала.
Член - функция, която приема число и проверява дали е част от интервала.
Член - функция, която връща броя на простите числа в интервала.
Член - функция, която връща броя на числата в интервала, които са палиндорми.
Член - функция, която връща броя на числата, които нямат повтарящи цифри.
Член - функция, която връща дали началото и края на интервала са степени на 2 - ката. ([2, 16] - истина)
Член - функция, която приема интервал и връща сечението на текущия интервал с подадения. (Сечението на[1, 5][3, 7] e[3, 5]).
Член - функция, която приема интервал и връща дали подадения(като параметър) интервал е подинтервал на текущия(обектът, от който се извиква функцията).
Пример за работа с класа :

int main()
{
	Interval t1(3, 10); // [3, 10]
	Interval t2(4, 14); // [4, 14]
	Interval t3; // [0, 0]

	Interval result = t1.intersect(t2); // [4, 10]

	t2.isSuperInterval(result); //true

	result.calcPrimeNumbersInTheInterval() // 2 (only 5 and 7)
}
