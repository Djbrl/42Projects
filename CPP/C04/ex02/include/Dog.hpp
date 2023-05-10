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

#ifndef __DOG_H__
# define __DOG_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal
{
private:
	Brain *_brain;
public:
    Dog();
    Dog(const Dog& d);
    Dog& operator=(const Dog& d);
    virtual ~Dog();

    virtual void makeSound() const;
    Brain* getBrain() const;
};


#endif