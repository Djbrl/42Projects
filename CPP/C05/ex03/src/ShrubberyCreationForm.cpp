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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:Form(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& p)
:Form(p)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& p)
{
	if (this != &p)
	{
	    setSignatureStatus(p.getSignatureStatus());
		setExecGrade(p.getExecGrade());
		setExecGrade(p.getExecGrade());
	}
	return (*this);	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyForm -> trashbin" << std::endl;
}

#include <fstream>
void ShrubberyCreationForm::execute(const Bureaucrat& b)const
{
	std::ifstream infile;
	
    if (b.getGrade() >= getExecGrade())
        throw GradeTooLowException();
    else
    {
        infile.open("tree.txt");
        if (!infile)
            std::cout << "Couldn't open tree file." << std::endl;
        std::string fileName = this->getName() + "_shrubbery";
        std::ofstream outfile(fileName.c_str());
        if (!outfile)
            std::cout << "Coudln't create shrubbery file." << std::endl;
        std::string line;
        while(getline(infile, line))
            outfile << line << std::endl;
        outfile.close();
        infile.close();
    }
}