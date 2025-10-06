#pragma once

#include "AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern(void);

		AForm*	makeForm(const std::string form_name, const std::string target) const;

		class	FormDoesNotExistException : public std::exception {
			const char*	what() const throw();
		};
};