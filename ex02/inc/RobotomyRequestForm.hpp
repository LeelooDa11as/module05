#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		bool	seeded;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		const std::string&	getTarget(void) const;
		void				execute(Bureaucrat const &executor) const;
};


#endif