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

void    ClapTrap::print(const std::string str)
{
    std::cout << YLW << str << END<< std::endl;
}


ClapTrap::ClapTrap() : name("Random dude"), hp(10), mana(10), ad(0)
{
    print("# - (Default ClapTrap [" + name + "] constructor called)");
}

ClapTrap::ClapTrap(const std::string n) : name(n), hp(10), mana(10), ad(0)
{
    print("# - (ClapTrap string [" + name + "] constructor called)");
}

ClapTrap::~ClapTrap()
{
    print("# - (Default ClapTrap [" + name + "] destructor called)");
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    if (this != &src)
        *this = src;
    print("# - (Copy operator called)");
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &src)
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

void    ClapTrap::attack(const std::string &target)
{
    if (mana > 0 && hp > 0)
    {
        std::cout << ">> " + target + " was attacked by " + getName() + " and took " << getAD() << " damage!" << std::endl;
        mana--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (getHP() == 0)
    {
        std::cout << ">> " << getName() + " is already dead!" << std::endl;
        return ;
    }
    if (amount >= getHP())
    {
        setHP(0);
        std::cout << ">> " + getName() + " took " << amount << " damage and has " << getHP() << " HP left!" << std::endl;
    }
    else
    {
        setHP(getHP() - amount);
        std::cout << ">> " + getName() + " took " << amount << " damage and has " << getHP() << " HP left!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (getHP() < 10 && getHP() > 0)
    {
        if (getHP() + amount <= 10)
            setHP(getHP() + amount);
        else
            setHP(10);
        std::cout << ">> " + getName() + " repaired himself, regaining " << amount << " HP. He now has " << getHP() << " HP!"  << std::endl;
        mana--;
    }
    else if (getHP() == 10)
        std::cout << ">> " + getName() + " tried to repair himself, but is already full HP!" << std::endl;    
    else if (getHP() == 0)
        std::cout << ">> " + getName() + " is dead and can't repair himself!" << std::endl;    
}


//GETS AND SETS

void ClapTrap::setHP(int n)
{ hp = n; }
void ClapTrap::setMana(int n)
{ mana = n; }
void ClapTrap::setAD(int n)
{ ad = n; }
int ClapTrap::getHP()
{ return hp; }
int ClapTrap::getMana()
{ return mana; }
int ClapTrap::getAD()
{ return ad; }
std::string ClapTrap::getName()
{ return name; }