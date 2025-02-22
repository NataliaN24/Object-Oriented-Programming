# C++ Programming Topic 01

## 🗂 Namespaces
Namespaces

## 📋 Enumerations, Structures, and Unions
Enumerations, Structures, and Unions. Types of Enumerations and Differences

## 🔧 Working with Instances
Initialization, Accessing Elements, Nesting, Working with Functions, Working with Arrays

## 📐 Object/Instance Size, Alignment, and Padding
Size of Objects/Instances, Alignment and Padding, Endianness and Checking for Big/Little Endian

## 🔺 Example with N Triangles

![image](https://github.com/user-attachments/assets/411b20dc-a361-4551-8086-7eb28b762b29)

### Task 2 🧮
Implement a `Rational` structure for working with rational numbers.

- **Functions to Implement:**
  - Addition ➕
    - *Резлизирайте функция за събиране.*
  - Subtraction ➖
    - *Резлизирайте функция за изваждане.*
  - Multiplication ✖️
    - *Резлизирайте функция за умножение.*
  - Division ➗
    - *Резлизирайте функция за деление.*
  - Function to check if an instance (object) of the new type is a valid rational number.
    - *Имплементирайте функция, която приема истанция(обект) от новия тип и връща дали е валидно рационално число.*
  - Function to determine if the rational number is an integer.
    - *Имплементирайте функция, която връща дали е цяло число.*

# ТЕОРЕТИЧНИ ЗАДАЧИ
  ## Задача 1: Намерете грешките в кода, поправете ги и кажете какво ще отпечата
```cpp
  #include <iostream>
using namespace std;

enum Fruit {
	APPLE,
	ORANGE
};

enum Color {
	RED = 107,
	BLUE,
	ORANGE // Грешка: Дублиране на ORANGE
};

enum class Cars {
	BMW,
	AUDI
};

int main() {
    
	cout << BLUE << endl;
	cout << (BMW == RED); // Грешка: BMW е от enum class и не може да се сравнява с RED
}
```
## задача 2
какво ще отпечата кодът?
```cpp
#include <iostream>
#include <cstdint>
using namespace std;

enum Fruit : uint8_t { APPLE = 1000, ORANGE };

int main() {
    cout << ORANGE;
}
```
uint8_t поддържа само 0-255.
APPLE = 1000 надвишава 255 
ще отпечата 0

```cpp
#include <iostream>
#include <cstdint>
using namespace std;

enum Fruit : uint8_t {
	APPLE = 255,
	ORANGE
};

int main() {
    cout << (int)ORANGE;
}
```
APPLE = 255 е окей, това е максимумът за uint8_t.

ORANGE = 255 + 1 = 256, но uint8_t поддържа само 8 бита, така че 256 се трункира до 0.

ако беше 254 тогава щеше да се отпечата 255
 
