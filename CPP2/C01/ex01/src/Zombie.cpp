/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:24 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:35:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << name << " : *explodes*" << std::endl ;
}

std::string Zombie::get_name()
{
    return name;
}

void    Zombie::set_name(std::string str)
{
    name = str;
}

void    Zombie::announce(void)
{
    std::cout << get_name() << " : BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
