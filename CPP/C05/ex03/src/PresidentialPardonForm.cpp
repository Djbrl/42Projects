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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:Form(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p)
:Form(p)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	if (this != &p)
	{
	    setSignatureStatus(p.getSignatureStatus());
		setExecGrade(p.getExecGrade());
		setExecGrade(p.getExecGrade());
	}
	return (*this);	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PardonForm -> trashbin" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& b)const
{
	if (getSignatureStatus() == false)
	{
        std::cout << "Turn back and go get this form signed first !" << std::endl;
        return ;
    }
	if (b.getGrade() >= getExecGrade())
		throw GradeTooLowException();
    else
    {
        std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
        std::cout << std::endl;
    }
}