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
    std::cout << "==ABOVE 1 INIT TEST==" << std::endl;
    try
    {
        Bureaucrat belowone = Bureaucrat("dude", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==BELOW 150 INIT TEST==" << std::endl;
    try
    {
        Bureaucrat belowone = Bureaucrat("dude", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "==BELOW 150 TEST==" << std::endl;
    Bureaucrat test = Bureaucrat("patrick", 150);
    try
    {
        test.demoteEmployee();
    }
    
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << YLW << "Exception caught: " << END << e.what() << std::endl;
    }
    std::cout << "==PROMOTE/DEMOTE TEST==" << std::endl;
    std::cout << test << std::endl;
    test.promoteEmployee();
    test.promoteEmployee();
    test.demoteEmployee();
    std::cout << test << std::endl;
    std::cout << "==ABOVE 1 TEST==" << std::endl;
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
    return 0;
}