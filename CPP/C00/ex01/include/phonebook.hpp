/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:36:23 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:36:28 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cctype>

	class contactProfile
	{
	private:
		std::string	fname;
		std::string	lname;
		std::string	nick;
		std::string	num;
		std::string	secret;

	public:
		contactProfile();
		~contactProfile();
		void		set_contact();
		std::string get_fname();
		std::string get_lname();
		std::string get_nick();
		std::string get_num();
		std::string get_secret();
	};

	class phoneBook
	{
	private:
		contactProfile entry[8];
		int     index;

	public:
		phoneBook();
		~phoneBook();
		void    add();
		void	bulk_add();
		void    search(std::string name);
	};

	std::string nosignal_getline();
	std::string search_getline();
	std::string random_string();
#endif

