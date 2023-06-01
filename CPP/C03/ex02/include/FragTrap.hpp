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

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
protected:

public:
    FragTrap();
    FragTrap(std::string str);
    FragTrap(const FragTrap& s);
    FragTrap& operator=(const FragTrap& s);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif