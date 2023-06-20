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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:Form(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& p)
:Form(p)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& p)
{
	if (this != &p)
	{
	    setSignatureStatus(p.getSignatureStatus());
		setExecGrade(p.getExecGrade());
		setExecGrade(p.getExecGrade());
	}
	return (*this);	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyForm -> trashbin" << std::endl;
}

#include <cstdlib>
void RobotomyRequestForm::execute(const Bureaucrat& b)const
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
        srand(time(0));
        int n = rand();
        if (n % 2)
            std::cout << getName() << " 's robotomy was successful !" << std::endl;
        else
            std::cout << getName() << " didn't survive the operation..." << std::endl;
        std::cout << std::endl;
    }
}