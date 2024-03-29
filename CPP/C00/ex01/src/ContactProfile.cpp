/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactProfile.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:38 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:35:39 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

ContactProfile::ContactProfile()
{
}

ContactProfile::~ContactProfile()
{
}

std::string ContactProfile::get_fname()
{
    return fname;
}

std::string ContactProfile::get_lname()
{
    return lname;
}

std::string ContactProfile::get_nick()
{
    return nick;
}

std::string ContactProfile::get_num()
{
    return num;
}
std::string ContactProfile::get_secret()
{
    return secret;
}

void ContactProfile::set_contact()
{
    std::cout << "\nContact Form:\n" << std::endl;
    std::cout << "First Name: ";
    fname = nosignal_getline();
    while (fname.empty() || (fname[0] == '\n' && fname.length() == 1))
       fname = nosignal_getline();
    std::cout << "Last Name: ";
    lname = nosignal_getline();
    while (lname.empty() || (lname[0] == '\n' && lname.length() == 1))
        lname = nosignal_getline();
    std::cout << "Nickname: ";
    while (nick.empty() || (nick[0] == '\n' && nick.length() == 1))
        nick = nosignal_getline();
    std::cout << "Phone: ";
    while (num.empty() || (num[0] == '\n' && num.length() == 1))
        num = nosignal_getline();
    std::cout << "... deepest secret ? ";
    while (secret.empty() || (secret[0] == '\n' && secret.length() == 1))
        secret = nosignal_getline();
    std::cout << std::endl;
}
