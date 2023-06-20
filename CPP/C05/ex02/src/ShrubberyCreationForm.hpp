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

#ifndef __ShrubberyCreationForm__HPP__
# define  __ShrubberyCreationForm__HPP__

# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& p);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& p);
        virtual ~ShrubberyCreationForm();

        virtual void execute(const Bureaucrat& b) const;
};

#endif