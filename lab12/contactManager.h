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

void menu();

Contact createContact();

template <typename Contact>
void addContact(Vector<Contact>* v);

template <typename Contact>
void deleteContact(Vector<Contact>* v);

template <typename Contact>
void editContact(Vector<Contact>* v);

template <typename Contact>
void showContacts(Vector<Contact>* v);

template <typename Contact>
void printContact(Vector<Contact>* v, Contact data, size_t i);

#endif // CONTACTMANAGER_H