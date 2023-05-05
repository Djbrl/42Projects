/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:36:11 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:36:12 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

static std::string spaces(size_t N) {
    return std::string(N, ' ');
}

static int is_number(const std::string& str)
{
    for (int i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
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
	std::cout << "|  INDEX   |FIRST NAME|LAST  NAME|NICK NAME|\n";
	while (i < index)
	{
		if (entry[i].get_fname().length() > 10)
			firstname = entry[i].get_fname().substr(0, 9) + ".";
		else
			firstname = entry[i].get_fname();
		if (entry[i].get_lname().length() > 10)
			lastname = entry[i].get_lname().substr(0, 9) + ".";
		else
			lastname = entry[i].get_lname();
		if (entry[i].get_nick().length() > 10)
			nickname = entry[i].get_nick().substr(0, 9) + ".";
		else
			nickname = entry[i].get_nick();
		std::cout << "|" + spaces(9) << i + 1 << "|" \
			<< firstname + spaces(10 - firstname.length())<< \
			"|" <<  lastname  + spaces(10 - lastname.length()) << \
			"|" << nickname + spaces(10 - nickname.length() - 1) << \
			"|\n\n";
		i++;
	}
	std::cout << "Number of contacts : " << index << std::endl;
	std::cout << "Index ? ";
	std::string contact_index = nosignal_getline();
	if (contact_index.length() < 1 || !is_number(contact_index))
	{
        std::cout << "\nInvalid input.\n\n";
		return ;
	}
    if (std::stoi(contact_index) <= index && std::stoi(contact_index) > 0)
    {
        i = std::stoi(contact_index) - 1;
        std::cout << "\n| CONTACT  |\n" << "|" \
            << entry[i].get_fname() << "|\n" \
            << "|" << entry[i].get_lname() << "|\n" \
            << "|" << entry[i].get_nick() << "|\n" \
            << "|" << entry[i].get_num() << "|\n" \
            << "|" << entry[i].get_secret() << "|\n" \
            << std::endl;
    }
    else
    {
        std::cout << "\nInvalid index.\n\n";
        return ;
    }
}