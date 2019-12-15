#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>

/**
* ������� ���� ���������, �������� ����� ������.
*/
void filePrint(std::fstream& file);

/**
* �������� ��������� ������ � ����� �����.
*/
void fileAppend(std::fstream& file, char* str);

/**
* ������� ������ � �� ��������, � ������� ���� ��������� ���������; 
*/
void fileSearch(std::fstream& file, char* needle);

/**
* ������������ ����, ������ ������ � ��������� �������.
*/
void fileRemoveString(std::fstream& file, char* name, size_t lineno);

/**
* ������������ ����, ������� ��������� ��������� ����� ������� � ��������� �������.
*/
void fileInsertString(std::fstream& file, char* name, char* insert, size_t lineno);

#endif // FILEMANAGER_H
