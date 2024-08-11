# C++ Programming Topic 02

## 💧 Streams in C++

### 📂 Standard Streams
Introduction to the standard input, output, and error streams.

### 📝 Text Files
- **Stream Hierarchy**
- **Stream Interface**

### 📁 File I/O Streams
- **File Input/Output**
  - Working with file streams to read from and write to files.
- **Modes of Operation**
  - Different modes for opening and working with files (e.g., `std::ios::in`, `std::ios::out`).
- **Stream State Flags**
  - Flags indicating the current state of a stream (e.g., `std::ios::goodbit`, `std::ios::failbit`).

### 📍 File Positioning
- **File Positioning**
  - Techniques for positioning within a file (e.g., `seekg`, `seekp`).

### 📏 Example Functions
- **File Size**
  - Function example that returns the size of a file.
- **Line Count**
  - Function example that returns the number of lines in a text file.
 ---

## 📋 Tasks

### Задача 1
Напишете програма, която отпечатва собствения си код.

### Задача 2
Напишете функция, която приема име на съществуващ файл и връща броя на редовете в него.

### Задача 3
Напишете функция, която приема име на съществуващ файл и копира съдържанието на съществуващия файл в нов файл.

### Задача 4
Напишете функция, която приема имената на два текстови файла, в които са записани цели числа в сортиран вид. Числата са разделени с интервал. Запишете в нов файл числата от двата файла в сортиран вид. Числата отново да са разделени с интервал.

### Задача 5
Напишете функции, които запазват и четат масив от студенти в текстов файл.

### Задача 6
Напишете програма, която чете comma-separated values (CSV) файл със студенти със следните 4 полета: Първо име, Фамилно име, Стринг на факултетен номер, Имейл.

Със стартирането на програмата потребителят да въвежда име на файл, който да бъде зареден в паметта.

- Напишете функция, която след зареждане на файла да отпечатва на стандартния изход информация за студента при подаден факултетен номер.
- Напишете функция, която по подаден факултетен номер, специалност и низ, променя email-a на студента, който има дадения факултетен номер и учи подадената специалност, с подадения низ.
- Напишете функцията, която приема низ (име на файл) и запазва студентите в същия формат (CSV). Т.е. при повторно пускане на програмата да може да прочете новия генериран файл.

**! Студентите имат уникални факултетни номера, в рамките на една специалност !**

### Simple Interface Example

```bash
Open file: 
>students.csv
File successfully opened!
>print 123 ComputerScience
Name = Stefan Velkov, Speciality: Computer science Email: stefan@yahoo.com, FN: 123
>edit 123 ComputerScience stecho@abv.bg
>print 123 ComputerScience
Name = Stefan Velkov, Email: stecho@abv.bg, FN: 123
>save students2.csv
file students2.csv successfully saved!
