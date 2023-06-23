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

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string str) : name(str), item(NULL)
{
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
    if (item != NULL)
        std::cout << name << " attacks with their " << item->getType() << std::endl;
    else
        std::cout << name << " attacks with their bare hands !" << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    item = &w;
}