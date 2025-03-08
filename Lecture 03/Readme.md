# C++ Programming Topic 03

## 📂 Working with `fstream`

### 📜 Opening Files for Reading and Writing
- Exploring the different methods of opening files with `fstream` and their characteristics.

### 📁 Binary Files
- **Saving Objects to a Binary File**
  - How to save objects in a binary file using `fstream`.
- **Reading Objects from a Binary File**
  - How to read objects from a binary file.
- **Example of Saving/Reading an Array of Objects**
  - Example of saving and reading an array of objects (of one type) in a file.
- **Example of Replacing a Character with Another in a File**
  - Reading and writing with `fstream` to replace characters in a file.

---
## 📋 Задачи

### Задача 1
Да се напишат програми, които запазват/четат масиви от обекти, които не използват динамична памет.

### Задача 2
Да се напише функция, която намира големината на файл.

### Задача 3
Да се напише функция, която заменя всяко срещане на символ във файл с друг символ. Съдържанието на файла не трябва да се зарежда в паметта.

### Задача 4

Задача 4:

Да се реализира програма за изглед и модификация на двоични файлове (hex viewer). При стартиране на програмата трябва да се въведе път до двоичен файл и да зареди съдържанието на файла в паметта. След като файлът се е заредил в паметта, трябва да поддържате следните операции:

Преглед на файла (view) отпечатва байтовете на файла (в шестнайсетична бройна система). След това да се отпечатат интерпретацията на байтовете като символи. Ако байтът отговаря на малка/голяма латинска буква, то да се отпечата символа. В противен случай да се отпечатва точка.
Промяна на байт по индекс (change ).
Премахване на последния байт (remove)
Добавяне на байт в края (add ).
Запазване на промените в същия файл (save)
Запазване на промените в друг файл (save as )
Нека имаме двоичен файл, myData.dat, който се е получил след изпълнението на следния c++ код:
``cpp
int x = 25409;
ofstream file(“myData.dat”, std::ios::binary);
file.write( (const char*)&x, sizeof(x));
Да се реализира прост интерфейс, с който да се извикват написаните фунцкии през конзолата.
``
Важно Не се ползволява използването на stl, както и std::hex.

Пример (входът от потребителя започва с '>'):
``
Enter a file path:
> myData.dat
File loaded successfully! Size: 4 bytes 
> view
41 63 00 00
A  c  .  . 
>change 1 65 
Operation successfully executed!
> view 
41 65 00 00 
A  e  .  . 
> remove 
> view
41 65 00 
A  e   . 
>save
``
File successfully saved
Забележка: Не се изисква поддържането на конзолен интерфейс. Можете само да реализирате функциите и да ги изпробвате в main функцията.
