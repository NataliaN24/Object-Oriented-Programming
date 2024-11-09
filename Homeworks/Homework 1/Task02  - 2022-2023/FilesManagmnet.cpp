#include<iostream>
#include<fstream>
#include"FilesManagment.h"
int myStrcmp(const char* ch1, const char* ch2) {//function from an internet source
	while (*ch1 && (*ch1 == *ch2)) {
		ch1++;
		ch2++;
	}
	return*(const unsigned char*)ch1 - *(const unsigned char*)ch2;

}
void MyStrcpy(char* dest, const char* src) {//function from an internet source
	size_t index = 0;
	while (src[index] != '\0') {
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
}

size_t myStrlen(const char* word) {
	size_t length = 0;
	while (*word != '\0') {
		length++;
		word++;
	}
	return length;
}
char* myStrcat(const char* str1, const char* str2) {//function from an internet source
	size_t len1 = myStrlen(str1);
	size_t len2 = myStrlen(str2);
	char* result = new char[len1 + len2 + 1];
	MyStrcpy(result, str1);
	MyStrcpy(result + len1, str2);
	return result;
}
void FileManager::writeToFile(const char* filename) {
	std::ofstream out(filename, std::ios::out);
	if (!out.is_open()) {
		std::cout << "Error!" << std::endl;
		return;

	}
	for (size_t i = 0; i < currentNum_files; i++) {
		File& file = files[i];
		out << file.getName() << ' ';
		out << file.getContent() << ' ';
		out << file.getSize() << ' ';
		out << file.getCreationTime().getHours() << ":" << file.getCreationTime().getMins() << ":" << file.getCreationTime().getSeconds() << ' ' << file.getCreationDate().getDay() <<
			"." << file.getCreationDate().getMonth() << "." << file.getCreationDate().getYear() << ' ';
		out << file.getModificationTime().getHours() << ":" << file.getModificationTime().getMins() << ":" << file.getModificationTime().getSeconds() << ' ' << file.getModificationDate().getDay() <<
			"." << file.getModificationDate().getMonth() << "." << file.getModificationDate().getYear() << std::endl;
		AccessRights  accessRights = file.getAccessRights();
		for (int i = 0; i < 3; i++) {
			out << accessRights.hasReadPermission(i) << " ";
		}
		for (int i = 0; i < 3; i++) {
			out << accessRights.hasWritePermission(i) << " ";
		}
		for (int i = 0; i < 3; i++) {
			out << accessRights.hasExecutePermission(i) << " ";
		}

	}
	out.close();

}
void FileManager::readToFile(const char* filename) {
	std::ifstream in(filename, std::ios::in);
	if (!in.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}
	char name[NAME_LENGTH + 1];
	char content[CONTENT_LENGTH + 1];
	size_t size, day, month, year, hours, mins, seconds;
	bool read[3], write[3], execute[3];
	char userType;
	while (in >> name >> content >> size >> hours >> mins >> seconds >> day >> month >> year) {
		Date creationDate(day, month, year);
		Time creationTime(hours, mins, seconds);
		in >> hours >> mins >> seconds >> day >> month >> year;
		Date modificationDate(day, month, year);
		Time modificationTime(hours, mins, seconds);
		AccessRights accessRights;
		for (int i = 0; i < 3; i++) {
			in >> read[i];
		}
		for (int i = 0; i < 3; i++) {
			in >> write[i];
		}
		for (int i = 0; i < 3; i++) {
			in >> execute[i];
		}
		accessRights.setReadPermission(0, read[0]);
		accessRights.setReadPermission(1, read[1]);
		accessRights.setReadPermission(2, read[2]);
		accessRights.setWritePermission(0, write[0]);
		accessRights.setWritePermission(1, write[1]);
		accessRights.setWritePermission(2, write[2]);
		accessRights.setExecutePermission(0, execute[0]);
		accessRights.setExecutePermission(1, execute[1]);
		accessRights.setExecutePermission(2, execute[2]);
		createFile(name, creationTime );
		editFile(name, content, modificationTime, modificationDate);
	}
	in.close();

}


FileManager::FileManager(int maxFiles) {
	this->maxFiles = maxFiles;
	files = new File[maxFiles];
	currentNum_files = 0;
}
FileManager::~FileManager() {
	delete[]files;
	
}
void  FileManager::createFile(const char* filename, const Time& CreationTime) {

	if (currentNum_files < maxFiles) {
		files[currentNum_files] = File(filename, " ", 0, CreationTime,Time(), Date(), Date(), AccessRights());
		currentNum_files++;
		std::cout << "File is created successfully!" << std::endl;
	}
	else {
		std::cout << "Error! File cannot be created!" << std::endl;
	}

}
void FileManager::editFile(const char* filename, const char* content, const Time& modificationTime, const Date& modificationDate) {
	for (size_t i = 0; i < currentNum_files; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			files[i].setContent(content);
			files[i].setSize(myStrlen(content));
			files[i].setModificationTime(modificationTime);
			files[i].setModificationDate(modificationDate);
			std::cout << "File is edited successfully!" << std::endl;
			return;

		}
	}
	std::cout << "Error! File cannot be edited!" << std::endl;


}
void FileManager::addTextToFile(const char* filename, const char* content,int size,int modificiationHour,int modificationMinutes,int modificationSeconds,
	int modificationDay,int modificationMonth,int modificationYear,AccessRights userRights) {
	for (size_t i = 0; i < currentNum_files; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			int oldSize = files[i].getSize();
			if (size <= CONTENT_LENGTH - oldSize) {
				char*newContent=myStrcat(files[i].getContent(), content);
				files[i].setContent(newContent);
				files[i].setSize(oldSize + size);
				Time modificationTime(modificiationHour, modificationMinutes, modificationSeconds);
				Date modificationDate(modificationDay, modificationMonth, modificationYear);
				files[i].setModificationTime(modificationTime);
				files[i].setModificationDate(modificationDate);
				files[i].setUserAccessRights(userRights);
				
				delete[] newContent;
				std::cout << "Text is added successfully!" << std::endl;
				return;
			}
		}
	}
	std::cout << "Error! Text cannot be added!" << std::endl;
	return;
	
}
void FileManager::deleteFile(const char* filename) {
	for (size_t i = 0; i < currentNum_files; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			for (size_t j = i + 1; j < currentNum_files; j++) {
				files[j - 1] = files[j];
			}
			currentNum_files--;
			return;
		}
	}
}
void FileManager::changeRights(const char* filename, char userType, char userRole) {
	for (size_t i = 0; i < currentNum_files; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			AccessRights rights = files[i].getAccessRights();
			switch (userType) {
			case 'u': 
				switch (userRole) {
				case 'r': 
					rights.setReadPermission(0, true);
					break;
				case 'w':
					rights.setWritePermission(0, true);
					break;
				case 'x': 
					rights.setExecutePermission(0, true);
					break;
				default:
					std::cout << "Invalid user role: " << userRole << std::endl;
					return;
				}
				break;
			case 'g': 
				switch (userRole) {
				case 'r': 
					rights.setReadPermission(1, true);
					break;
				case 'w': 
					rights.setWritePermission(1, true);
					break;
				case 'x': 
					rights.setExecutePermission(1, true);
					break;
				default:
					std::cout << "Invalid user role: " << userRole << std::endl;
					return;
				}
				break;
			case 'o': 
				switch (userRole) {
				case 'r': 
					rights.setReadPermission(2, true);
					break;
				case 'w': 
					rights.setWritePermission(2, true);
					break;
				case 'x': 
					rights.setExecutePermission(2, true);
					break;
				default:
					std::cout << "Invalid user role: " << userRole << std::endl;
					return;
				}
				break;
			default:
				std::cout << "Invalid user type: " << userType << std::endl;
				return;
			}
			
			std::cout << "Access rights changed for file " << filename << std::endl;
			return;
		}
	}
	std::cout << "File " << filename << " not found." << std::endl;
}
void FileManager::printInfoForAFile(const char* filename) {
	for (size_t i = 0; i < currentNum_files; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			std::cout << "Name:" << files[i].getName();
			std::cout << "Size:" << files[i].getSize();
			std::cout << "Created on:"; files[i].getCreationTime(); std::cout << ' '; files[i].getCreationDate();
			std::cout << "Last modified on:";  files[i].getModificationTime(); std::cout << ' '; files[i].getModificationDate();
			std::cout << "Rights:"; files[i].getAccessRights();
			return;

		}
	}
	std::cout << "Error! File not found!" << std::endl;
}

void FileManager::printContents(const char* filename, char userType) {
	for (size_t i = 0; i <currentNum_files ; i++) {
		if (myStrcmp(files[i].getName(), filename) == 0) {
			bool hasPermission = false;
			if (userType == 'u') {
				hasPermission = files[i].getAccessRights().hasReadPermission('u');
			}
			else if (userType == 'g') {
				hasPermission = files[i].getAccessRights().hasReadPermission('g');
			}
			else if (userType == 'o') {
				hasPermission = files[i].getAccessRights().hasReadPermission('o');
			}
			if (hasPermission) {
				std::cout << files[i].getContent() << std::endl;
				return;
			}
			else {
				std::cout << "Error! You do not have the rights to read!" << std::endl;
				return;
			}
		}
	}
	std::cout << "Error! File not found!" << std::endl;
}

void FileManager::printAllFiles()const {
	for (size_t i = 0; i < currentNum_files; i++) {
		std::cout << "Name: " << files[i].getName() << std::endl;
		std::cout << "Size: " << files[i].getSize() << std::endl;
		std::cout << "Created on: "; files[i].getCreationTime(); std::cout << ' '; files[i].getCreationDate(); std::cout << std::endl;
		std::cout << "Last modified on: "; files[i].getModificationTime(); std::cout << ' '; files[i].getModificationDate(); std::cout << std::endl;
		std::cout << "Rights: "; files[i].getAccessRights(); std::cout << std::endl;
		std::cout << "Content: " << std::endl; files[i].getContent(); std::cout << std::endl;
	}

}
void FileManager::SortFilesByName() {
	for (size_t i = 0; i < currentNum_files - 1; i++) {
		for (size_t j = 0; j < currentNum_files - i - 1; j++) {
			if (myStrcmp(files[j].getName(), files[j + 1].getName()) > 0) {
				File temp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = temp;
			}
		}
	}
}
void FileManager::SortFilesByModificationTime() {
	
		for (size_t i = 0; i < currentNum_files - 1; i++) {
			for (size_t j = 0; j < currentNum_files - i - 1; j++) {
				if (files[j].getModificationTime().getHours() > files[j + 1].getModificationTime().getHours()) {
					File temp = files[j];
					files[j] = files[j + 1];
					files[j + 1] = temp;
				}
			}
		}
}
void FileManager::SortFilesByCreationTime()  {


	for (size_t i = 0; i < currentNum_files - 1; i++) {
		for (size_t j = 0; j < currentNum_files - i - 1; j++) {
			if (files[j].getCreationTime().getHours() > files[j + 1].getCreationTime().getHours()) {
				File temp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = temp;
			}
		}
	}

}
void FileManager::SortFilesBySize() {
	for (size_t i = 0; i < currentNum_files - 1; i++) {
		for (size_t j = 0; j < currentNum_files - i - 1; j++) {
			if (files[j].getSize() > files[j + 1].getSize()) {
				File temp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = temp;
			}
		}
	}

}