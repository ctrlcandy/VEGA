#include "fileManager.h"

#include <iostream>
#include <fstream>

int main()
{
	char name[260];
	std::cout << "enter file name" << std::endl;
	std::cin >> name;

	std::fstream file(name, std::ios::in | std::ios::out | std::ios::app);
	filePrint(file);
	
	std::cout << "file append" << std::endl;
	char str[50];
	std::cin.ignore();
	std::cin.getline(str, 50);
	fileAppend(file, str);
	filePrint(file); 
	
	std::cout << "file search" << std::endl;
	char needle[50];
	std::cin.ignore();
	std::cin.getline(needle, 50);
	fileSearch(file, needle); 

	std::cout << "file remove string" << std::endl;
	fileRemoveString(file, name, 6);
	filePrint(file); 

	std::cout << "file insert string" << std::endl;
	char insert[50];
	std::cin.getline(insert, 50);
	fileInsertString(file, name, insert, 6);
	filePrint(file);

	file.close();
	return 0;
}