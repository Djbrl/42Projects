/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:37:43 by user42            #+#    #+#             */
/*   Updated: 2022/01/27 15:05:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string n) : name(n), hp(10), mana(10), ad(0)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
        *this = src;
}
