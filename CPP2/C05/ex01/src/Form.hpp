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

#ifndef __FORM_H__
# define __FORM_H__

# define YLW "\033[0;33m"
# define END "\033[0;0m"
# include <iostream>
// # include "Bureaucrat.hpp"
// # include <stdbool>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signature;
        const int           _signGrade;
        const int           _execGrade;

    public:
        Form(const std::string name, int signGrade, int execGrade);
        Form(const Form &src);
        ~Form();
        Form& operator=(const Form &src);

        //gets and sets
        const std::string     getName() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        int             getSignatureStatus() const;

        void            beSigned(Bureaucrat &src);

        //exceptions
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, const Form &right_side);

#endif