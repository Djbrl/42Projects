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
    Bureaucrat test = Bureaucrat("patrick", 150);
    try
    {
        test.demoteEmployee();
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << YLW << "Exception caught: " << END << e.what() << std::endl;
    }
    std::cout << test << std::endl;
    test.promoteEmployee();
    test.promoteEmployee();
    std::cout << test << std::endl;
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