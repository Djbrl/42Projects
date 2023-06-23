#ifndef __INTERN__HPP
# define __INTERN__HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        Form *makeForm(std::string name, std::string target);
        Form *createPPF(std::string target);
        Form *createSCF(std::string target);
        Form *createRRF(std::string target);
};

#endif