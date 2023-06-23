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

Fixed::Fixed():FixedPointnum(0)
{
}

Fixed::Fixed(const Fixed &src)
{
  *this = src;
}

Fixed   &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		FixedPointnum = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (FixedPointnum);
}

void	Fixed::setRawBits(int const raw)
{
	FixedPointnum = raw;
}

int		Fixed::toInt(void) const
{
	return (FixedPointnum >> bits);
}

float	Fixed::toFloat(void) const
{
	return (float)(FixedPointnum) / (1 << bits);
}

Fixed::Fixed(const int num):FixedPointnum(num << bits)
{
}

Fixed::Fixed(const float num):FixedPointnum((int)(std::roundf(num * (1 << bits))))
{
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	return(a.toFloat() > b.toFloat() ? a : b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	return(a.toFloat() < b.toFloat() ? a : b);
}

Fixed max(Fixed &a, Fixed &b)
{
	return(a.toFloat() > b.toFloat() ? a : b);
}

Fixed min(Fixed &a, Fixed &b)
{
	return(a.toFloat() < b.toFloat() ? a : b);
}