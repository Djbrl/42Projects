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

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string str, int n) : name(str)
{
    if (n < 1)
        throw GradeTooLowException();
    else
        grade = n;
    if (n > 150)
        throw GradeTooHighException();
    else
        grade = n;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    if (this != &src)
        *this = src;
}

Bureaucrat      &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this != &src)
        grade = src.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat: Grade too low");
}

//gets and sets
const std::string     Bureaucrat::getName() const
{
    return name;
}

int             Bureaucrat::getGrade() const
{
    return grade;
}

void            Bureaucrat::setGrade(int n)
{
    if (n > 0 && n <= 150)
        grade = n;
    else
    {
        grade = 0;
    }
}

void            Bureaucrat::promoteEmployee()
{
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}

void            Bureaucrat::demoteEmployee()
{
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &src)
{
    return stream << src.getName() << ", bureaucrat grade " << src.getGrade(); 
}