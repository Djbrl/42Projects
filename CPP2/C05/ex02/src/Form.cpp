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

#include "Form.hpp"

Form::Form(const std::string str, int signGrade, int execGrade) 
    : _name(str), _signature(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooLowException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooHighException();
}

int Form::getExecGrade() const {return _execGrade;}

int Form::getSignGrade() const {return _signGrade;}

Form::Form(const Form &src)
    :_name(src.getName()), _signature(src.getSignatureStatus()), _signGrade(src.getSignGrade()),
	_execGrade(src.getExecGrade())
{
}

Form      &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        _signature = src._signature;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form -> trashbin" << std::endl;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Form Signature: Grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Form Signature: Grade too low");
}

//gets and sets
const std::string     Form::getName() const
{
    return _name;
}

std::ostream &operator<<(std::ostream &stream, const Form &src)
{
    return stream << src.getName() << ", Form signature grade: " << src.getSignGrade() << ", Form exec grade: " << src.getExecGrade() << ", Signature statuts: " << src.getSignatureStatus();
}

int Form::getSignatureStatus() const
{
    return _signature;
}

void Form::beSigned(Bureaucrat &src)
{
    if (src.getGrade() <= _signGrade)
        _signature = true;
    else
        throw GradeTooLowException();
}

void            Form::setSignGrade(int n)
{ (void)n; }

void            Form::setExecGrade(int n)
{ (void)n; }

void            Form::setSignatureStatus(bool status)
{ _signature = status; }

