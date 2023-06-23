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

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# define YLW "\033[0;33m"
# define END "\033[0;0m"
# include <iostream>
# include <cmath>

class ClapTrap
{
    protected:
        std::string name;
        int hp;
        int mana;
        int ad;
        void    print(std::string str);

    public:
        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap();
        ClapTrap    &operator=(const ClapTrap &src);
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        //getters and setters
        void setHP(int n);
        void setMana(int n);
        void setAD(int n);

        int getHP();
        int getMana();
        int getAD();
        std::string getName();
};

#endif