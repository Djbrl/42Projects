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

# include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hp = 100;
    mana = 50;
    ad = 20;
    name = "Random guard";
    print("# - (Default FragTrap [" + name + "] constructor called)");
}

FragTrap::FragTrap(const std::string n) : ClapTrap(n)
{
    hp = 100;
    mana = 50;
    ad = 20;
    name = n;
    print("# - (FragTrap string [" + name + "] constructor called)");
}

FragTrap::~FragTrap()
{
    print("# - (Default FragTrap [" + name + "] destructor called)");
}

FragTrap::FragTrap(const FragTrap &src)
{
    if (this != &src)
        *this = src;
    print("# - (Copy operator called)");
}

FragTrap    &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        name = src.name;
        hp = src.hp;
        ad = src.ad;
        mana = src.mana;
    }
    print("# - (Overloaded '=' operator called)");
    return (*this);
}

void    FragTrap::highFiveGuys()
{
    print("high five!");
}
