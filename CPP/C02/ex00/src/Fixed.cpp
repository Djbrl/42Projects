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

#include "../include/Fixed.hpp"

//CONSTRUCTORS
Fixed::Fixed() : FixedPointnum(0)
{
    std::cout << "Defaut constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
    if (this != &src)
        FixedPointnum = src.FixedPointnum;
    std::cout << "Copy assignment called\n";
}

//OPERATORS
Fixed   &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        FixedPointnum = src.FixedPointnum;
    std::cout << "Copy assignment operator called\n";
    return (*this);
}

//METHODS
int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return FixedPointnum;
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    FixedPointnum = raw;
}
