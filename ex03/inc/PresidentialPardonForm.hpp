#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		const std::string&	getTarget(void) const;
		void				execute(Bureaucrat const &executor) const;
};


#endif