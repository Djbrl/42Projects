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

std::ostream& operator<<(std::ostream& flux, const Fixed& f)
{
	return flux << f.toFloat();
}

bool	Fixed::operator>(const Fixed& src)
{
	return (FixedPointnum > src.FixedPointnum);
}

bool	Fixed::operator<(const Fixed& src)
{
	return (FixedPointnum < src.FixedPointnum);
}

bool	Fixed::operator>=(const Fixed& src)
{
	return (FixedPointnum >= src.FixedPointnum);
}

bool	Fixed::operator<=(const Fixed& src)
{
	return (FixedPointnum <= src.FixedPointnum);
}

bool	Fixed::operator==(const Fixed& src)
{
	return (FixedPointnum == src.FixedPointnum);
}

bool	Fixed::operator!=(const Fixed& src)
{
	return (FixedPointnum != src.FixedPointnum);
}

Fixed	Fixed::operator+(const Fixed& src)
{
	return (toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(const Fixed& src)
{
	return (toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(const Fixed& src)
{
	return (toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed& src)
{
	return (toFloat() / src.toFloat());
}

Fixed& Fixed::operator++(void) {
  ++FixedPointnum;
  return *this;
}

Fixed& Fixed::operator--(void) {
  --FixedPointnum;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;

  ++FixedPointnum;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;

  --FixedPointnum;
  return tmp;
}