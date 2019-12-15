#include "fileManager.h"

#include <iostream>
#include <fstream>
#include <cstring>

void filePrint(std::fstream& file)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	file.seekg(0, std::ios_base::beg);

	size_t i = 0;
	char buffer[500];
	while (!file.eof()) {
		i++;
		file.getline(buffer, 500);
		std::cout << i << " " << buffer << std::endl;
	}

	file.clear();
}

void fileAppend(std::fstream& file, char* str)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	file.seekg(0, std::ios::end);

	if (file.tellg() == 0)
		file << str;
	else
		file << std::endl << str;
}

void fileSearch(std::fstream& file, char* needle)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	file.seekg(0, std::ios_base::beg);

	size_t i = 0;
	char buffer[500];
	while (!file.eof()) {
		i++;
		file.getline(buffer, 500);
		if (strstr(buffer, needle) != nullptr)
			std::cout << i << " " << buffer << std::endl;
	}

	file.clear();
}

void fileRemoveString(std::fstream& file, char* fileName, size_t lineno)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	std::fstream tmpfile("tmpfile.txt", std::ios::in | std::ios::out | std::ios::app);
	file.seekg(0, std::ios_base::beg);

	size_t i = 0;
	char buffer[500];
	while (!file.eof()) {
		i++;
		file.getline(buffer, 500);
		if (i != lineno)
			fileAppend(tmpfile, buffer);
	}
	file.clear();

	file.close();
	remove(fileName);

	tmpfile.close();
	rename("tmpfile.txt", fileName);
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
}

void fileInsertString(std::fstream& file, char* fileName, char* insert, size_t lineno)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	std::fstream tmpfile("tmpfile.txt", std::ios::in | std::ios::out | std::ios::app);
	file.seekg(0, std::ios_base::beg);

	size_t i = 0;
	char buffer[500];
	while (!file.eof()) {
		i++;
		file.getline(buffer, 500);
		if (i == lineno)
			fileAppend(tmpfile, insert);
		fileAppend(tmpfile, buffer);
	}
	file.clear();

	file.close();
	remove(fileName);

	tmpfile.close();
	rename("tmpfile.txt", fileName);
	file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
}