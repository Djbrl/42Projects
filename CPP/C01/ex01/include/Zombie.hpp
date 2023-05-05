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

#ifndef HEADER_FILE_NAME_H
# define HEADER_FILE_NAME_H

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;

    public:

        Zombie();
        ~Zombie();
        std::string get_name(void);
        void        set_name(std::string str);
        void        announce(void);
};

Zombie      *zombieHorde(int n, std::string name);
#endif
