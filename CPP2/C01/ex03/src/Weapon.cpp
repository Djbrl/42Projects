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

#include "../include/Weapon.hpp"

Weapon::Weapon()
{
    type = "default weapon";
}

Weapon::Weapon(std::string str)
{
    type = str;
}

Weapon::~Weapon()
{
}

const std::string   &Weapon::getType()
{
    const std::string &typeREF = type;
    return typeREF;
}

void    Weapon::setType(std::string str)
{
    type = str;
}