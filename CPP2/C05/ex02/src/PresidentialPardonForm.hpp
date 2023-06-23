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

#ifndef __PRESIDENTIALPARDONFORM__HPP__
# define  __PRESIDENTIALPARDONFORM__HPP__

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& p);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& p);
        virtual ~PresidentialPardonForm();

        virtual void execute(const Bureaucrat& b) const;
};

#endif