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

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    hp = 100;
    mana = 100;
    ad = 30;
    name = "Bot";
    print("# - (Default FragTrap [" + name + "] constructor called)");
}

FragTrap::FragTrap(std::string str):ClapTrap(str)
{
    hp = 100;
    mana = 100;
    ad = 30;
    print("# - (Default FragTrap [" + name + "] string constructor called)");
}

FragTrap::~FragTrap()
{
    print("# - (Default FragTrap [" + name + "] destructor called)");
}

FragTrap::FragTrap(const FragTrap& s)
{
    *this = s;
    print("# - (Default FragTrap [" + name + "] copy constructor called)");
}

FragTrap&  FragTrap::operator=(const FragTrap& s)
{
    if (this != &s)
    {
        name = s.name;
        hp = s.hp;
        mana = s.mana;
        ad = s.ad;
    }
    print("# - (Default FragTrap [" + name + "] overloaded = operator called)");
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "high five! (the dante way)\n" << std::endl;
}
