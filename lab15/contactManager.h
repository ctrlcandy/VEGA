#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "vector.h"

enum Groups
{
	NO_GROUP = 1,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

struct Contact
{
	char name[80];
	char phone[12];
	int group;
};

void menu(char* filename);

template <typename Contact>
Contact createContact(Vector<Contact>* v);
void createContact(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i);

template <typename Contact>
void addContact(Vector<Contact>* v);

template <typename Contact>
void deleteContact(Vector<Contact>* v);
void deleteContact(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i);

template <typename Contact>
void editContact(Vector<Contact>* v);

void editOnlyContactName(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i);
void editOnlyContactPhone(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i);
void editOnlyContactGroup(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i);

template <typename Contact>
void showContacts(Vector<Contact>* v);

template <typename Contact>
void printContact(Vector<Contact>* v, Contact data, size_t i);

template <typename Contact>
void loadFromFile(Vector<Contact>* vector, std::fstream& file);

template <typename Contact>
void saveToFile(Vector<Contact>* vector, std::fstream& file, char* filename);

void parseCmdAndExecuteCommands(char* filename, const char* command, int argc, char* argv[]);

#endif // CONTACTMANAGER_H