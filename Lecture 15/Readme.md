# C++ Programming Topic 15

## Tree Structure of Objects in Polymorphic Hierarchy 🌳

### Key Concepts

- **Tree Structure** 🌲
- **Polymorphic Hierarchy** 🧩

### Example: Logical Expressions
# 📋 Задачи

## Задача 1:
Реализирайте клас за работа с изрази от множества. Трябва да имате:

**1.Функция за прасване на израз от стринг.**

**2.Функция, която приема елемент и връща дали елементът е част от полученото от израза множество**

**3.Функция, която приема 2 израза и връща дали се получава едно и също множество.**
```cpp
int main()
{
   //v - union
   //^ - intersection
       // '\' - set minus
       // '!' - complement
       // 'x' - relative complement

   SetCalculator s("(((A^B)vC)vX)");

   SetExpression::Element el;
   el.set('A', true); //element is in set A
   el.set('B', false); // element is NOT in set B
   el.set('C', true); // element is in set C

   std::cout << s.isElementIn(el);

       SetCalculator s1("(A^B)");
       SetCalculator s2("(!((!A)v(!B)))");
       s1 == s2; // true (De morgan laws)
}
 
