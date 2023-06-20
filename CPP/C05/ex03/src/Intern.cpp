#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
    std::cout << "wait, has anyone seen the intern ?" << std::endl;
}

Intern::Intern(const Intern &src)
{
    if (this != &src)
        *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    //intern has no attributes to copy
    (void)src;
    return *this;
}

Form *Intern::createPPF(std::string target)
{
    return new PresidentialPardonForm(target);
}

Form *Intern::createSCF(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::createRRF(std::string target)
{
    return new RobotomyRequestForm(target);
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
    Form *(Intern::*catalog[3])(std::string target);
    Form *ret = nullptr;
    int     i = 0;
    int     found = 0;

    catalog[0] = &Intern::createPPF;
    catalog[1] = &Intern::createSCF;
    catalog[2] = &Intern::createRRF;

    std::string request[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};

    for (i = 0; i < 3; i++)
	{
		if (request[i] == form)
		{
            std::cout << "Intern creates " <<  form << std::endl;
			ret = (this->*catalog[i])(target);
            found = 1;
			break ;
		}
	}
    if (!found)
    {
        std::cout << "boss I don't think this form exists?" << std::endl;
        return nullptr;
    }
    return ret;
}
