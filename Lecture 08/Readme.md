# C++ Programming Topics

C++ Programming Topic 08

## Static Member Data, Exceptions, and Exception Handling

Learn about static member data, exception handling, and exception safety in C++. This includes understanding exception hierarchies, handling exceptions in constructors and destructors, and achieving different levels of exception safety.

### Key Concepts

- **Static Member Data**: Understand how static member data is shared across all instances of a class.
- **Exceptions**: Learn how to use exceptions to handle errors and manage exceptional situations in C++.
- **Exception Handling**: Explore different techniques for catching and handling exceptions.
- **Exception Hierarchy**: Understand the hierarchy of exception types and how to use them effectively.
- **Exception Safety Levels**: Learn about different levels of exception safety and how to ensure your code is exception-safe.
- **Exceptions in Constructors and Destructors**: Handling exceptions that occur during object construction and destruction.

### 📋 Задачи

#### Задача 1: ImmutableString

Напишете клас `ImmutableString`, който не може да се променя. При създаването на два еднакви стринга, те трябва да споделят една и съща памет.

#### Задача 2: Exception Handling Task
Напишете програма, която по подаден път до папка, сканира тази папка на всеки 10 минути за файл с име inputFlights.txt. inputFlights има произволен брой редове, всеки от които е в следния формат: <origin> <dest> <priceInEuro>.

sof bER 43
mUN Lon 123
aTH sCH 3

origin и destination са стрингове само от латински букви с дължина 3, а priceInEuro е цяло число. Данните от всеки ред трябва да се конкатенират във файл outputFlights като двата стринга са същите, но всички малки букви са заместени с главни, а цената да е в лева (по курс 1.95).

SOF BER 83.85
MUN LON 239.85
ATH SCH 5.85
Напишете всяка функция за възможно най-общо предназначение и имплменетирайте приложението, така че да бъде коректно от към обработка на изключения
