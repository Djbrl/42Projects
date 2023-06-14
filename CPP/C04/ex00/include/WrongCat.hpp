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

#ifndef __WrongCat_H__
# define __WrongCat_H__

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		
	public:
		WrongCat();
		WrongCat(const WrongCat &c);
		~WrongCat();
		void	makeSound() const;
		WrongCat				&operator=(const WrongCat& c);
};

#endif