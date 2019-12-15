#include "contactManager.h"

#include <iostream>

int main(int argc, char* argv[])
{	
	if (argc == 2)
	{
		if (strcmp(argv[1], "--help") == 0)
		{
			std::cout << "Usage: contacts[option] <file>" << std::endl
				<< "Options :" << std::endl
				<< "	create-contact <name> <phone> <group>" << std::endl
				<< "	delete-contact <name>" << std::endl
				<< "	edit-contact-name <name> <new - name>" << std::endl
				<< "	edit-contact-phone <name> <new - phone>" << std::endl
				<< "	edit-contact-group <name>[<new - group>]" << std::endl
				<< "	show-contacts" << std::endl
				<< "	show-contacts-by-name <name>" << std::endl
				<< "	show-contacts-by-phone <phone>" << std::endl
				<< "	show-contacts-by-group <group>" << std::endl;
		}

		else menu(argv[1]);
	}
	else if (argc > 2)
	{
		const char* comName[9] = { "create-contact", "delete-contact", "edit-contact-name",
			"edit-contact-phone", "edit-contact-group", "show-contacts", "show-contacts-by-name",
			"show-contacts-by-phone", "show-contacts-by-group" };
		int comNum[9] = { 3, 1, 2, 2, 2, 0, 1, 1, 1 };

		for (size_t i = 0; i < 9; i++)
			if (argc == (comNum[i] + 3))
			{
				if (strcmp(argv[1], comName[i]) == 0)
				{
					parseCmdAndExecuteCommands(argv[argc-1], argv[1], argc, argv);
					return 0;
				}
				else if (strcmp(argv[2], comName[i]) == 0)
				{
					parseCmdAndExecuteCommands(argv[1], argv[2], argc, argv);
					return 0;
				}
			}
		std::cout << "No such command found. Type --help to get help." << std::endl;
	}
	return 0;
}
