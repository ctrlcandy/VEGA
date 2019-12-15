#include "contactManager.h"
#include "fileManager.h"
#include "vector.h"

#include <iostream>
#include<limits>
#include <fstream>

void menu(char* filename)
{
	Vector<Contact>* vector = createVector<Contact>();
	std::fstream file(filename, std::ios::in | std::ios::app);

	loadFromFile(vector, file);

	std::cout << "List of available commands :" << std::endl
		<< "1. Create contact" << std::endl
		<< "2. Delete contact" << std::endl
		<< "3. Edit contact" << std::endl
		<< "4. Show contact(s)" << std::endl
		<< "5. Exit" << std::endl;

	int command;
	while (true)
	{
		std::cout << "Main menu command: ";
		std::cin >> command;

		if (std::cin.fail())
			command = 0;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		switch (command)
		{
		case 1:
			addContact(vector);
			break;
		case 2:
			deleteContact(vector);
			break;
		case 3:
			editContact(vector);
			break;
		case 4:
			showContacts(vector);
			break;
		case 5:
			while (true)
			{
				std::cout << "Are you sure you want to save changes?" << std::endl
					<< "YES/NO" << std::endl;

				char confirm[5];
				std::cin.getline(confirm, 80);
				if (strcmp(confirm, "NO") == 0 || strcmp(confirm, "no") == 0)
					return;
				else if (strcmp(confirm, "YES") == 0 || strcmp(confirm, "yes") == 0)
				{
					saveToFile(vector, file, filename);
					return;
				}
			}
		default:
			std::cout << "Enter correct number to run command" << std::endl;
		}
	}
}

void parseCmdAndExecuteCommands(char* filename, const char* command, int argc, char* argv[])
{
	Vector<Contact>* vector = createVector<Contact>();
	std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);
	loadFromFile(vector, file);

	for (size_t i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], command) == 0)
		{
			if (strcmp("create-contact", command) == 0)
				createContact(vector, file, filename, argv, i);

			else if (strcmp("delete-contact", command) == 0)
				deleteContact(vector, file, filename, argv, i);

			else if (strcmp("edit-contact-name", command) == 0)
				editOnlyContactName(vector, file, filename, argv, i);

			else if (strcmp("edit-contact-phone", command) == 0)
				editOnlyContactPhone(vector, file, filename, argv, i);

			else if (strcmp("edit-contact-group", command) == 0)
				editOnlyContactGroup(vector, file, filename, argv, i);

			else if (strcmp("show-contacts", command) == 0)
			{
				for (size_t j = 0; j < vector->size; j++)
					printContact(vector, vector->data[j], j);
			}

			else if (strcmp("show-contacts-by-name", command) == 0)
				for (size_t j = 0; j < vector->size; j++)
				{
					if (strcmp(vector->data[j].name, argv[i + 1]) == 0)
						printContact(vector, vector->data[j], j);
				}

			else if (strcmp("show-contacts-by-phone", command) == 0)
				for (size_t j = 0; j < vector->size; j++)
				{
					if (strcmp(vector->data[j].phone, argv[i + 1]) == 0)
						printContact(vector, vector->data[j], j);
				}

			else if (strcmp("show-contacts-by-group", command) == 0)
			{
				int group;
				if (strcmp(argv[i + 1], "FAMILY") == 0)
					group = 2;
				else if (strcmp(argv[i + 1], "FRIENDS") == 0)
					group = 3;
				else if (strcmp(argv[i + 1], "COLLEAGUES") == 0)
					group = 4;
				else
					group = 1;

				for (size_t j = 0; j < vector->size; j++)
					if (vector->data[j].group == group)
						printContact(vector, vector->data[j], j);
			}
		}
	}
}

template <typename Contact>
void saveToFile(Vector<Contact>* vector, std::fstream& file, char* filename)
{
	file.close();
	file.open(filename, std::ios::out | std::ios::trunc);
	char str[200];
	for (size_t i = 0; i < getSize(vector); i++)
	{
		memset(str, 0, 200);

		strcat(str, vector->data[i].name);
		strcat(str, ";");

		strcat(str, vector->data[i].phone);
		strcat(str, ";");

		if (vector->data[i].group == 2)
			strcat(str, "FAMILY");
		else if (vector->data[i].group == 3)
			strcat(str, "FRIENDS");
		else if (vector->data[i].group == 4)
			strcat(str, "COLLEAGUES");
		else
			strcat(str, "NO_GROUP");

		fileAppend(file, str);
	}
	file.close();
}

template <typename Contact>
void loadFromFile(Vector<Contact>* vector, std::fstream& file)
{
	if (!file.is_open())
	{
		std::cout << "Error!!!1";
		return;
	}

	file.seekg(0, std::ios_base::beg);

	char buffer[500];
	char* pch;

	while (!file.eof()) {
		file.getline(buffer, 500);
		if (strlen(buffer) == NULL)
			continue;

		Contact contact;

		pch = strtok(buffer, ";");
		memcpy(contact.name, pch, sizeof(contact.name));


		pch = strtok(NULL, ";");
		memcpy(contact.phone, pch, sizeof(contact.phone));

		pch = strtok(NULL, ";");
		if (strcmp(pch, "FAMILY") == 0)
			contact.group = 2;
		else if (strcmp(pch, "FRIENDS") == 0)
			contact.group = 3;
		else if (strcmp(pch, "COLLEAGUES") == 0)
			contact.group = 4;
		else
			contact.group = 1;

		append(vector, contact);
	}

	file.clear();
}

template <typename Contact>
void addContact(Vector<Contact>* vector)
{
	Contact contact = createContact(vector);
	append(vector, contact);
}

template <typename Contact>
Contact createContact(Vector<Contact>* vector)
{
	std::cout << "Contact creation" << std::endl;

	std::cout << "Enter name: " << std::endl;
	char name[80];

	while (true)
	{
		bool isContinue = false;
		std::cin.getline(name, 80);
		for (size_t i = 0; i < vector->size; i++)
			if (strcmp(vector->data[i].name, name) == 0)
			{
				std::cout << "This name is already in use!" << std::endl
					<< "Enter new name:" << std::endl;
				isContinue = true;
				break;
			}
		if (!isContinue)
			break;
	}

	Contact contact;
	strcpy(contact.name, name);

	std::cout << "Enter phone number: " << std::endl;
	std::cin >> contact.phone;

	std::cout << "Enter group: " << std::endl;
	char group[80];

	std::cin.ignore();
	std::cin.getline(group, 80);

	if (strcmp(group, "FAMILY") == 0)
		contact.group = 2;
	else if (strcmp(group, "FRIENDS") == 0)
		contact.group = 3;
	else if (strcmp(group, "COLLEAGUES") == 0)
		contact.group = 4;
	else
		contact.group = 1;

	return contact;
}

void createContact(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i)
{
	for (size_t j = 0; j < vector->size; j++)
		if (strcmp(vector->data[j].name, argv[i + 1]) == 0)
			return;

	Contact contact;
	strcpy(contact.name, argv[i + 1]);
	strcpy(contact.phone, argv[i + 2]);
	if (strcmp(argv[i + 3], "FAMILY") == 0)
		contact.group = 2;
	else if (strcmp(argv[i + 3], "FRIENDS") == 0)
		contact.group = 3;
	else if (strcmp(argv[i + 3], "COLLEAGUES") == 0)
		contact.group = 4;
	else
		contact.group = 1;

	append(vector, contact);
	saveToFile(vector, file, filename);
}

template <typename Contact>
void deleteContact(Vector<Contact>* vector)
{
	std::cout << "Enter name: " << std::endl;
	char name[80];
	std::cin.getline(name, 80);

	for (size_t i = 0; i < getSize(vector); i++)
	{
		if (strcmp(vector->data[i].name, name) == 0) {
			erase(vector, i);
			return;
		}
	}
	std::cout << "No such name found" << std::endl;
}

void deleteContact(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i)
{
	for (size_t j = 0; j < vector->size; j++)
	{
		if (strcmp(vector->data[j].name, argv[i + 1]) == 0) {
			erase(vector, j);
			saveToFile(vector, file, filename);
			return;
		}
	}
}

template <typename Contact>
void editContact(Vector<Contact>* vector)
{
	std::cout << "Edit contact" << std::endl;
	std::cout << "Enter name : " << std::endl;
	char name[80];
	std::cin.getline(name, 80);

	for (size_t i = 0; i < getSize(vector); i++)
	{
		if (strcmp(vector->data[i].name, name) == 0) {
			int command;

			std::cout << "Edit contact field" << std::endl
				<< "1. Edit name" << std::endl
				<< "2. Edit phone number" << std::endl
				<< "3. Edit group" << std::endl
				<< "4. Back" << std::endl;

			while (true)
			{
				std::cout << "Command: " << std::endl;
				std::cin >> command;

				if (std::cin.fail())
					command = 0;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());

				switch (command)
				{
				case 1:
					std::cout << "Enter new name : " << std::endl;
					char newName[80];

					while (true)
					{
						bool isContinue = false;
						std::cin.getline(newName, 80);
						for (size_t i = 0; i < vector->size; i++)
							if (strcmp(vector->data[i].name, newName) == 0)
							{
								std::cout << "This name is already in use!" << std::endl
									<< "Enter new name :" << std::endl;
								isContinue = true;
								break;
							}
						if (!isContinue)
							break;
					}
					strcpy(vector->data[i].name, newName);

					return;
				case 2:
					std::cout << "Enter new phone number : " << std::endl;
					char newPhone[12];
					std::cin >> newPhone;

					strcpy(vector->data[i].phone, newPhone);
					return;
				case 3:
					std::cout << "Enter new group : " << std::endl;

					char newGroup[80];
					std::cin.getline(newGroup, 80);

					if (strcmp(newGroup, "FAMILY") == 0)
						vector->data[i].group = 2;
					else if (strcmp(newGroup, "FRIENDS") == 0)
						vector->data[i].group = 3;
					else if (strcmp(newGroup, "COLLEAGUES") == 0)
						vector->data[i].group = 4;
					else
						vector->data[i].group = 1;

					return;
				case 4:
					return;
				default:
					std::cout << "Enter correct number to run command" << std::endl;
				}
			}
		}
	}
	std::cout << "No such name found" << std::endl;
}

void editOnlyContactName(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i)
{
	for (size_t j = 0; j < vector->size; j++)
		if (strcmp(vector->data[j].name, argv[i + 2]) == 0)
			return;

	for (size_t j = 0; j < vector->size; j++)
		if (strcmp(vector->data[j].name, argv[i + 1]) == 0)
		{
			strcpy(vector->data[j].name, argv[i + 2]);
			saveToFile(vector, file, filename);
		}

}

void editOnlyContactPhone(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i)
{
	for (size_t j = 0; j < vector->size; j++)
		if (strcmp(vector->data[j].name, argv[i + 1]) == 0)
		{
			strcpy(vector->data[j].phone, argv[i + 2]);
			saveToFile(vector, file, filename);
		}
}

void editOnlyContactGroup(Vector<Contact>* vector, std::fstream& file, char* filename, char* argv[], size_t i)
{
	for (size_t j = 0; j < vector->size; j++)
		if (strcmp(vector->data[j].name, argv[i + 1]) == 0)
		{
			if (strcmp(argv[i + 2], "FAMILY") == 0)
				vector->data[j].group = 2;
			else if (strcmp(argv[i + 2], "FRIENDS") == 0)
				vector->data[j].group = 3;
			else if (strcmp(argv[i + 2], "COLLEAGUES") == 0)
				vector->data[j].group = 4;
			else
				vector->data[j].group = 1;

			saveToFile(vector, file, filename);
		}
}

template <typename Contact>
void showContacts(Vector<Contact>* vector)
{
	std::cout << "Print contact(s):" << std::endl
		<< "1. By name" << std::endl
		<< "2. By phone number" << std::endl
		<< "3. By group" << std::endl
		<< "4. All contacts" << std::endl
		<< "5. Back" << std::endl;

	int command;
	std::cin >> command;

	if (std::cin.fail())
		command = 0;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	while (true)
	{
		switch (command)
		{
		case 1:
			char name[80];
			std::cout << "Enter name : " << std::endl;
			std::cin.getline(name, 80);

			for (size_t i = 0; i < getSize(vector); i++)
				if (strcmp(vector->data[i].name, name) == 0)
				{
					printContact(vector, vector->data[i], i);
					return;
				}
			std::cout << "No such name found" << std::endl;

			return;
		case 2:
			char phone[12];
			std::cout << "Enter phone : " << std::endl;
			std::cin >> phone;

			for (size_t i = 0; i < getSize(vector); i++)
				if (strcmp(vector->data[i].phone, phone) == 0) {
					printContact(vector, vector->data[i], i);
					return;
				}
			std::cout << "No such phone found" << std::endl;

			return;
		case 3:
			std::cout << "Enter group : " << std::endl
				<< "1. NO_GROUP" << std::endl
				<< "2. FAMILY" << std::endl
				<< "3. FRIENDS" << std::endl
				<< "4. COLLEAGUES" << std::endl;

			int group;
			std::cin >> group;

			if (group != 1 && group != 2 && group != 3 && group != 4)
				std::cout << "Enter correct number to run command" << std::endl;
			else {
				for (size_t i = 0; i < getSize(vector); i++)
				{
					if (vector->data[i].group == group)
						printContact(vector, vector->data[i], i);
				}
			}

			return;
		case 4:
			for (size_t i = 0; i < getSize(vector); i++)
				printContact(vector, vector->data[i], i);
			return;
		case 5:
			return;
		default:
			std::cout << "Enter correct number to run command" << std::endl;
		}
	}
}

template <typename Contact>
void printContact(Vector<Contact>* vector, Contact data, size_t i)
{
	std::cout << "*" << " [";
	switch (vector->data[i].group)
	{
	case NO_GROUP:
		std::cout << "NO_GROUP";
		break;
	case FAMILY:
		std::cout << "FAMILY";
		break;
	case FRIENDS:
		std::cout << "FRIENDS";
		break;
	case COLLEAGUES:
		std::cout << "COLLEAGUES";
		break;
	}
	std::cout << "] " << vector->data[i].name << " --- " << vector->data[i].phone << std::endl;
}
