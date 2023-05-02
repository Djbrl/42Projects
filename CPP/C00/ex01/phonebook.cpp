#include <iostream>
#include <cstring>
#include <unistd.h>
#include "phonebook.hpp"

std::string nosignal_getline()
{
	std::string str;
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "\nExit. (Ctrl + D)" << std::endl;
		exit(EXIT_SUCCESS);
	}
	return str;
}

void phoneBook::add()
{
	if (index < 8) // Make sure there is space in the contact list
	{
		entry[index].set_contact();
		std::cout << "\"" << entry[index].get_fname() << " " << entry[index].get_lname() << \
			" (" << entry[index].get_num() << ")\" has been added your contact list !\n\n====================================\n" << std::endl;
		index++;
	}
	else
		std::cout << "Your contact list is full.\n\n====================================\n" << std::endl;
}

void phoneBook::search(std::string )
{
	int 		i;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;

	i = 0;
	if (index == 0)
	{
		std::cout << "\nEmpty.\n\n";
		return ;
	}
	std::cout << "|\tINDEX\t|\tFIRST NAME\t|\tLAST NAME\t|\tNICKNAME\t|\n";
	while (i < index)
	{
		if (entry[i].get_fname().length() > 10)
			firstname = entry[i].get_fname().substr(0, 10) + ".";
		else
			firstname = entry[i].get_fname();
		if (entry[i].get_lname().length() > 10)
			lastname = entry[i].get_lname().substr(0, 10) + ".";
		else
			lastname = entry[i].get_lname();
		if (entry[i].get_nick().length() > 10)
			nickname = entry[i].get_nick().substr(0, 10) + ".";
		else
			nickname = entry[i].get_nick();
		std::cout << "|\t" << i + 1 << "\t|\t" << firstname << \
			"\t|\t" <<  lastname << "\t|\t" << nickname << \
			"\t|\n\n";
		i++;
	}
	std::cout << "Number of contacts : " << index << std::endl;
	std::cout << "Index ? " << std:endl << std::endl;
	char index = nosignal_getline();
	

}

int main() {
	phoneBook phone;

	std::cout << "\n====================================\nPhonebook Manager\n" << std::endl;
	while (true) {
		std::cout << "Type ADD to add a new contact" << std::endl;
		std::cout << "Type SEARCH to search for a contact" << std::endl;
		std::cout << "Type EXIT to exit the program\n" << std::endl;

		std::string input = nosignal_getline();
		if (input == "EXIT") {
			break;
		} else if (input == "ADD") {
			phone.add();
		} else if (input == "SEARCH") {
			phone.search("bro");
		} else {
			std::cout << "Invalid input.\n\n====================================" << std::endl;
		}
	}

	return 0;
}