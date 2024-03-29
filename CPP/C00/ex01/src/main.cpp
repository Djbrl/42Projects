/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:47 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:35:48 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

std::string nosignal_getline()
{
    std::string str;
    std::getline(std::cin, str);

    std::string ret;
    for (char c : str) {
        if (std::isprint(c)) {
            ret += c;
        }
    }

    if (std::cin.eof())
    {
        std::cout << "\nExit. (Ctrl + D)" << std::endl;
        exit(EXIT_SUCCESS);
    }
    return ret;
}


int main() {
	PhoneBook phone;

	std::cout << "\n====================================\nPhoneBook Manager\n" << std::endl;
	while (true) {
		std::cout << "Type ADD to add a new contact" << std::endl;
		std::cout << "Type SEARCH to search for a contact" << std::endl;
		std::cout << "Type EXIT to exit the program\n" << std::endl;

		std::string input = nosignal_getline();
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search("bro");
		else
			std::cout << "Invalid input.\n\n====================================" << std::endl;
	}
	return 0;
}
