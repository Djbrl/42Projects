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

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# define YLW "\033[0;33m"
# define END "\033[0;0m"
# include <iostream>

class Bureaucrat
{
    private:
        const std::string   name;
        unsigned int        grade;

    public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat& operator=(const Bureaucrat &src);

    //gets and sets
    std::string     getName();
    unsigned int    getGrade();
    void            promoteEmployee(const Bureaucrat &employee);
    void            demoteEmployee(const Bureaucrat &employee);
    
};

std::ostream &operator<<(std::ostream &stream, const &Bureaucrat right_side);

#endif