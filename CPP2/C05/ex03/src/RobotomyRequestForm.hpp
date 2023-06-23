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

#ifndef __ROBOTOMYREQUESTFORM__HPP__
# define  __ROBOTOMYREQUESTFORM__HPP__

# include "Form.hpp"

class RobotomyRequestForm: public Form
{
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& p);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& p);
        virtual ~RobotomyRequestForm();

        virtual void execute(const Bureaucrat& b) const;
};

#endif