#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>

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

void menu();
Contact createContact();
void addContact(std::vector<Contact>& vector);
void deleteContact(std::vector<Contact>& vector);
void editContact(std::vector<Contact>& vector);
void showContacts(std::vector<Contact>& vector);
void printContact(std::vector<Contact>& vector, size_t i);

#endif // CONTACTMANAGER_H