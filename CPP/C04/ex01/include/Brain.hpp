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

#ifndef _brain_H__
# define _brain_H__

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		
	public:
	    Brain();
        virtual ~Brain();
        Brain(const Brain &src);
        Brain  &operator=(const Brain &src);
        std::string returnIdea(int i);
};

#endif