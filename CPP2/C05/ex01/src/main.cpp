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

int main()
{
    //DEMOTE BELOW 150
    std::cout << "==DEMOTE BELOW 150==" << std::endl;
    Bureaucrat test = Bureaucrat("patrick", 150);
    try
    {
        test.demoteEmployee();
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << YLW << "Exception caught: " << END << e.what() << std::endl;
    }

    //OPERATOR TEST
    std::cout << "==OPERATOR TEST==" << std::endl;
    std::cout << test << std::endl;
    
    //STANDARD PROMOTION TEST
    std::cout << "==STANDARD PROMOTION TEST==" << std::endl;
    test.promoteEmployee();
    test.promoteEmployee();
    std::cout << test << std::endl;

    //PROMOTE ABOVE 1
    std::cout << "==PROMOTE ABOVE 1==" << std::endl;
    test.setGrade(1);
    try
    {
        test.promoteEmployee();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << YLW <<"Exception caught: " << END << e.what() << std::endl;
    }
    test.demoteEmployee();
    std::cout << test << std::endl;

    //FORM SIGN HIGH TEST
    std::cout << "==FORM SIGN HIGH TEST==" << std::endl;
    Form a1 = Form("A1 Form", 1, 1);
    try
    {
        test.signForm(a1);
    }
    catch(const std::exception& e)
    {
        std::cerr << YLW <<"Exception caught: " << END << e.what() << std::endl;
    }

    //SIGNABLE FORM TEST
    std::cout << "==SIGNABLE FORM TEST==" << std::endl;
    Form a2 = Form("A2 Form", 2, 1);
    try
    {
        test.signForm(a2);
    }
    catch(const std::exception& e)
    {
        std::cerr << YLW <<"Exception caught: " << END << e.what() << std::endl;
    }
    return 0;
}