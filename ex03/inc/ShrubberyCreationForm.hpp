#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	std::string target;
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		const std::string&	getTarget(void) const;
		void	execute(Bureaucrat const &executor) const;
		
};


#endif
