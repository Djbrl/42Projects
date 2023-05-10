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

#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int					FixedPointnum;
        static const int	bits = 8;
    
    public:
        int 				getRawBits() const;
        void				setRawBits(int const raw);
        float               toFloat() const;
        int                 toInt() const;

                            Fixed();
                            Fixed(const int n);
                            Fixed(const float n);
                            Fixed(const Fixed &src);
                            ~Fixed();
        Fixed               &operator=(const Fixed &src);

        Fixed               &operator*=(const Fixed &src);
        Fixed&              operator++(void);
        Fixed               operator+(const Fixed &src);
        Fixed&              operator--(void);
        Fixed               operator-(const Fixed &src);
        Fixed               operator++(int);
        Fixed               operator--(int);
        Fixed               operator*(const Fixed &src);
        Fixed               operator/(const Fixed &src);
    

        static Fixed        max(const Fixed& a, const Fixed& b);
	    static Fixed        min(const Fixed& a, const Fixed& b);
        
        bool                operator<(const Fixed &src);
        bool                operator>(const Fixed &src);
        bool                operator<=(const Fixed &src);
        bool                operator>=(const Fixed &src);
        bool                operator==(const Fixed &src);
        bool                operator!=(const Fixed &src);
};

std::ostream               &operator<<(std::ostream &flux, const Fixed& src);
#endif 