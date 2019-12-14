#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>

/**
* Вывести файл построчно, указывая номер строки.
*/
void filePrint(std::fstream& file);

/**
* Добавить указанную строку в конец файла.
*/
void fileAppend(std::fstream& file, char* str);

/**
* Вывести строки с их номерами, в которых
* есть указанная подстрока; (указанную подстроку в строке
* выводить в ВЕРХНЕМ регистре. (не сделаль))
*/
void fileSearch(std::fstream& file, char* needle);

/**
* Перезаписать файл, удалив строку с указанным номером.
*/
void fileRemoveString(std::fstream& file, char* name, size_t lineno);

/**
* Перезаписать файл, вставив указанную подстроку перед строкой с указанным номером.
*/
void fileInsertString(std::fstream& file, char* name, char* insert, size_t lineno);

#endif // FILEMANAGER_H