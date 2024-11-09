#include<iostream>
#include"AccessRights.h"

AccessRights::AccessRights() {
		for (size_t i = 0; i < 3; i++) {
			readPermission[i] = false;
			writePermission[i] = false;
			executePermission[i] = false;
		}
	}
void AccessRights::setPermission(const char* accessRights) {
	for (size_t i = 0; i < 3; i++) {
		readPermission[i] = (accessRights[i * 3] == 'r');
		writePermission[i] = (accessRights[i * 3 + 1] == 'w');
		executePermission[i] = (accessRights[i * 3 + 2] == 'x');
	}
}
bool AccessRights::hasReadPermission(char userType)const {
	switch (userType) {
	case 'u'://user
		return readPermission[0];
	case 'g'://group
		return readPermission[1];
	case 'o'://other
		return readPermission[2];
	default:
		return false;
	}

}
bool AccessRights:: hasWritePermission( char userType)const {
	switch (userType) {
	case 'u':
		return writePermission[0];
	case 'g':
		return writePermission[1];
	case 'o':
		return writePermission[2];
	default:
		return false;
	}
}

bool AccessRights:: hasExecutePermission(char userType)const {
	switch (userType) {
	case 'u':
		return executePermission[0];
	case 'g':
		return executePermission[1];
	case 'o':
		return executePermission[2];
	default:
		return false;
	}
}

void AccessRights::setReadPermission(int userRole, bool value) {
	readPermission[userRole] = value;
}

void AccessRights::setWritePermission(int userRole, bool value) {
	writePermission[userRole] = value;
}

void AccessRights::setExecutePermission(int userRole, bool value) {
	executePermission[userRole] = value;
}

void AccessRights::printPermissions() const {
	std::cout << "Read Permissions:" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "User type " << i << ": " << readPermission[i] << "\n";
	}

	std::cout << "Write Permissions:";
	for (int i = 0; i < 3; i++) {
		std::cout << "User type " << i << ": " << writePermission[i] << "\n";
	}

	std::cout << "Execute Permissions:";
	for (int i = 0; i < 3; i++) {
		std::cout << "User type " << i << ": " << executePermission[i] << "\n";
	}

}