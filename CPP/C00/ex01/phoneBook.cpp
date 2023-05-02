#include "phonebook.hpp"

phoneBook::phoneBook()
{
    index = 0;
}

phoneBook::~phoneBook()
{
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
	std::cout << "Index ? ";
	std::string contact_index = nosignal_getline();
	if (contact_index.length() < 1)
	{
        std::cout << "\nInvalid input.\n\n";
		return ;
	}
    if (std::stoi(contact_index) <= index && std::stoi(contact_index) > 0)
    {
        i = std::stoi(contact_index) - 1;
        std::cout << "\n|\tCONTACT\t\t|\n" << "|\t" \
            << entry[i].get_fname() << "\t|\n" \
            << "|\t" << entry[i].get_lname() << "\t|\n" \
            << "|\t" << entry[i].get_nick() << "\t|\n" \
            << "|\t" << entry[i].get_num() << "\t|\n" \
            << "|\t" << entry[i].get_secret() << "\t|\n" \
            << std::endl;
    }
    else
    {
        std::cout << "\nInvalid index.\n\n";
        return ;
    }
}