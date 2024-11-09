#include<iostream>
#include<fstream>
#include"FilesManagment.h"
//Natalia Nakollofski 1MI8000034 GROUP 1 SI
using std::cout;
using std::cin;
using std::endl;

const int NAME_SIZE = 64;
const int CHARACTER = 512;
const int ACCESS_RIGHTS = 9;


int main() {
    FileManager fs(10);

    int choice;
    do {
        cout << "File Manager Menu:" << endl;
        cout << "1. Add a new file" << endl;
        cout << "2. Edit an existing file" << endl;
        cout << "3. Add text to an existing file" << endl;
        cout << "4. Delete a file" << endl;
        cout << "5. Change file permissions" << endl;
        cout << "6. Print file contents" << endl;
        cout << "7. Print all files" << endl;
        cout << "8. Print one file" << endl;
        cout << "9. Sort  by name " << endl;
        cout << "10. Sort by creation time" << endl;
        cout << "11.Sort by time of last modification " << endl;
        cout << "12.Sort  by size" << endl;
        cout << "13.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:

            char filename1[100];
            std::cout << "Enter filename: ";
            std::cin >> filename1;
            Time creationTime = Time(12, 0, 0);
            fs.createFile(filename1, creationTime);
            break;
        case 2:

            char filename2[100], content[100];
            size_t hours, minutes, seconds;
            size_t day, month, year;
            std::cout << "Enter filename: ";
            std::cin >> filename2;

            std::cout << "Enter content: ";
            std::cin >> content;

            std::cout << "Enter modification hours ,minutes,seconds: ";
            std::cin >> hours >> minutes >> seconds;
            Time modificationTime(hours, minutes, seconds);

            std::cout << "Enter modification day,month ,year (dd mm yyyy): ";
            std::cin >> day >> month >> year;
            Date modificationDate(day, month, year);

            fs.editFile(filename2, content, modificationTime, modificationDate);
            break;
        case 3:
            char filename3[50];
            char content3[CONTENT_LENGTH];
            int size;
            size_t hour1, minutes1, seconds1;
            size_t  day1, month1, year1;
            char accessRights[10];

            std::cout << "Enter the name of the file to add text to: ";
            std::cin >> filename3;

            std::cout << "Enter the text to add to the file: ";
            std::cin.ignore();
            std::cin.getline(content3, CONTENT_LENGTH);

            std::cout << "Enter the size of the text to add: ";
            std::cin >> size;

            std::cout << "Enter the modification time (hh:mm:ss): ";
            std::cin >> hour1 >> minutes1 >> seconds1;

            std::cout << "Enter the modification date (dd.mm.yyyy): ";
            std::cin >> day1 >> month1 >> year1;

            std::cout << "Enter the access rights for the file (e.g. rwxr--r--): ";
            std::cin >> accessRights;

            AccessRights userRights;
            userRights.setPermission(accessRights);

            fs.addTextToFile(filename3, content3, size, hour1, minutes1, seconds1, day1, month1, year1, userRights);
            break;
        case 4:
            char filename4[50];
            std::cout << "Enter the name of the file to be deleted." << std::endl;
            cin >> filename4;
            fs.deleteFile(filename4);
            break;
        case 5:
            char  filename5[50];
            char userType, userRole;
            std::cout << "Enter filename: ";
            std::cin >> filename5;
            std::cout << "Enter user type (u/g/o): ";
            std::cin >> userType;
            std::cout << "Enter user role (r/w/x): ";
            std::cin >> userRole;
            fs.changeRights(filename5, userType, userRole);
            break;
        case 6:
            char filename6[100];
            char userType;

            std::cout << "Enter filename: ";
            std::cin >> filename6;

            std::cout << "Enter user type (u/g/o): ";
            std::cin >> userType;

            fs.printContents(filename6, userType);
            break;
        case 7:
            fs.printAllFiles();
            break;
        case 8:
            char filename7[50];
            cout << "Enter the name of the file that you want to be printed" << endl;
            cin >> filename7;

            fs.printInfoForAFile(filename7);
            break;
        case 9:
            fs.SortFilesByName();
            break;
        case 10:
            fs.SortFilesByCreationTime();
            break;
        case 11:
            fs.SortFilesByModificationTime();
            break;
        case 12:
            fs.SortFilesBySize();
            break;
        case 13:
            cout << "Exit" << endl;
            return;
            break;
        default:
            cout << "ERROR,INVALID CHOICE!" << endl;
            break;
        }
    } while (choice != 13);
    return 0;
}