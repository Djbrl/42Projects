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

# include "../include/ScavTrap.hpp"

void    ScavTrap::print(const std::string str)
{
    std::cout << YLW << str << END<< std::endl;
}


ScavTrap::ScavTrap() : ClapTrap()
{
    hp = 100;
    mana = 50;
    ad = 20;
    name = "Random guard";
    guardState = 0;
    print("# - (Default ScavTrap [" + name + "] constructor called)");
}

ScavTrap::ScavTrap(const std::string n) : ClapTrap(n)
{
    hp = 100;
    mana = 50;
    ad = 20;
    name = n;
    guardState = 0;
    print("# - (ScavTrap string [" + name + "] constructor called)");
}

ScavTrap::~ScavTrap()
{
    print("# - (Default ScavTrap [" + name + "] destructor called)");
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    if (this != &src)
        *this = src;
    print("# - (Copy operator called)");
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &src)
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

//MEMBER FUNCTIONS

void    ScavTrap::attack(const std::string &target)
{
    if (mana > 0 && hp > 0)
        std::cout << ">> " + target + " was attacked by Scavy Mc. " + getName() + " and took " << getAD() << " damage!" << std::endl;
}

// void    ScavTrap::takeDamage(unsigned int amount)
// {
//     if (getHP() == 0)
//     {
//         std::cout << ">> " << getName() + " is already dead!" << std::endl;
//         return ;
//     }
//     if (amount >= getHP())
//     {
//         setHP(0);
//         std::cout << ">> " + getName() + " took " << amount << " damage and has " << getHP() << " HP left!" << std::endl;
//     }
//     else
//     {
//         setHP(getHP() - amount);
//         std::cout << ">> " + getName() + " took " << amount << " damage and has " << getHP() << " HP left!" << std::endl;
//     }
// }

// void    ScavTrap::beRepaired(unsigned int amount)
// {
//     if (getHP() < 10 && getHP() > 0)
//     {
//         if (getHP() + amount <= 10)
//             setHP(getHP() + amount);
//         else
//             setHP(10);
//         std::cout << ">> " + getName() + " repaired himself, regaining " << amount << " HP. He now has " << getHP() << " HP!"  << std::endl;
//     }
//     else if (getHP() == 10)
//         std::cout << ">> " + getName() + " repaired himself, but is already full HP!" << std::endl;    
//     else if (getHP() == 0)
//         std::cout << ">> " + getName() + " is dead and can't repair himself!" << std::endl;    
// }

void    ScavTrap::guardGate()
{
    if (guardState == 0)
    {
        guardState = 1;
        std::cout << ">> " + getName() + " is now in Gate keeper mode. " << std::endl;        
    }
    else
    {
        guardState = 0;
        std::cout << ">> " + getName() + " is no longer in Gate keeper mode. " << std::endl;        
    }
}
//GETS AND SETS

// void ScavTrap::setHP(int n)
// { hp = n; }
// void ScavTrap::setMana(int n)
// { mana = n; }
// void ScavTrap::setAD(int n)
// { ad = n; }
// int ScavTrap::getHP()
// { return hp; }
// int ScavTrap::getMana()
// { return mana; }
// int ScavTrap::getAD()
// { return ad; }
// std::string ScavTrap::getName()
// { return name; }