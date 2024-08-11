# C++ Programming Topic 13

## Templates and Smart Pointers 🌟

### Key Concepts

- **Templates**
  - **Required Functions in Template Classes/Functions**
  - **Template Specializations**
- **Examples of Template Classes/Functions from the Standard Library**
- **Smart Pointers**
  - **Usage and Concept of `shared_ptr`, `weak_ptr`, `unique_ptr`**

### Example: Stack with Template Capacity and Queue with Resize Function
---

# 📋 Задачи

## Задача 1: Структура Опашка ⏳

Реализирайте структурата от данни опашка. Опашката трябва да работи с произволни типове. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

### Примерен интерфейс:

```cpp
int main()
{
   queue<int> q;
   q.push(3);
   q.push(5);
   q.push(10);

   cout << q.peek() << endl; //3
   q.pop();
   
   cout << q.peek() << endl; //5
   q.pop();

   cout << q.peek() << endl; //10
   q.pop();
   
   cout << q.isEmpty() << endl; //1	
}
```
## Задача 2: Създайте шаблонна опашка с k приоритета.
При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет.
```cpp
int main()
{
  kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
  
  q.push('A',0): //adds A with lowest priority: 0
  q.push('B',3);
  q.push('C',2);
  q.push('D',2);
  q.push('E',1);
  
  //q.push('F', 5); //error! No such priority!
  
  q.peek(); // B
  q.pop();
  
  q.peek(); // C
  q.pop();
  
  q.peek(); // D
  q.pop();
  
  q.peek(); // E
  q.pop();
  
  q.peek(); // A
  q.pop();
}
