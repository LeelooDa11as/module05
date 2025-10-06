#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern&	Intern::operator=(const Intern &other) {
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string form_name, const std::string target) const {

	std::string	forms[3] = {"Shrubbery", "RobotomyRequest", "PresidentialPardon"};
	int	i = 0;
	AForm *res = NULL;

	while(i < 3 && forms[i] != form_name )
		i++;
	switch (i) {
		case 0: {
			res = new ShrubberyCreationForm(target);
			break;
		}
		case 1: {
			res = new RobotomyRequestForm(target);
			break;
		}
		case 2: {
			res = new PresidentialPardonForm(target);
			break;
		}
		case 3: {
			throw(FormDoesNotExistException());
		}
	}
	return res;
}

const char* Intern::FormDoesNotExistException::what() const throw() {
	return ("This form does not exist. You go to the end of the line");
};