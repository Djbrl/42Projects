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

#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        std::string name;
        int hp;
        int mana;
        int ad;
        void    print(std::string str);
        bool guardState;

    public:
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap();
        FragTrap    &operator=(const FragTrap &src);
        std::string getName();
        void    highFiveGuys();
};

#endif