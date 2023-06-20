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

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat test = Bureaucrat("patrick", 2);
    std::cout << "==PARDON TEST==" << std::endl;
    Form *a1 = new PresidentialPardonForm("Thanos");
    try
    {
        test.signForm(*a1);
        a1->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==ROBOT TEST==" << std::endl;
    Form *a2 = new RobotomyRequestForm("Sub-Zero");
    try
    {
        test.signForm(*a2);
        a2->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==TREE TEST==" << std::endl;
    Form *a3 = new ShrubberyCreationForm("Garden-Permit-2-A");
    try
    {
        test.signForm(*a3);
        a3->execute(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete a1;
    delete a2;
    delete a3;
    return 0;
}