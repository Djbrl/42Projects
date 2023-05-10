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

#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <iostream>

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal();
		Animal(const Animal &a);
		virtual				~Animal();
		virtual std::string	getType() const;
		virtual void		setType(std::string str);
		virtual void		makeSound() const;
		Animal				&operator=(const Animal &a);
};

std::ostream& operator<<(std::ostream& o, const Animal& a);

#endif