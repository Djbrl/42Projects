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

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# define YLW "\033[0;33m"
# define END "\033[0;0m"
# include <iostream>


class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &src);

    //gets and sets
    const std::string     getName() const;
    int             getGrade() const;
    void            setGrade(int n);
    void            promoteEmployee();
    void            demoteEmployee();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &right_side);

#endif