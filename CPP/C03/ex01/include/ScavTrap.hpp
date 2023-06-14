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

#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        void    print(std::string str);
        bool guardState;

    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap();
        ScavTrap    &operator=(const ScavTrap &src);
        void    attack(const std::string &target);
        void    guardGate();
};

#endif