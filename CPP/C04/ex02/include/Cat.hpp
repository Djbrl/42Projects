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

#ifndef __CAT_H__
# define __CAT_H__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: virtual public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat& c);
        Cat& operator=(const Cat& c);
        virtual ~Cat();
        virtual void makeSound() const;
        std::string getIdea(int i);
        std::string getType() const;
};

#endif