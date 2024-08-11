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

Да се реализира програма за изглед и модификация на двоични файлове (hex viewer). При стартиране на програмата трябва да се въведе път до двоичен файл и да зареди съдържанието на файла в паметта. След като файлът се е заредил в паметта, трябва да поддържате следните операции:

- Преглед на файла (`view`) отпечатва байтовете на файла (в шестнайсетична бройна система). След това да се отпечатат интерпретацията на байтовете като символи. Ако байтът отговаря на малка/голяма латинска буква, то да се отпечата символа. В противен случай да
