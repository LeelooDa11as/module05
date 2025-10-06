
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;
class	AForm {
	private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;

	protected:
	void				exec_prep(Bureaucrat const &office_rat) const;

	public:
	
	AForm(void);
	AForm(const std::string &name, const int &sign_grade, const int &execute_grade);
	AForm(AForm const &base);
	AForm &operator=(AForm const &other);
	virtual ~AForm(void);
	
	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	const int&			getSignGrade(void) const;
	const int&			getExecuteGrade(void) const;

	void				beSigned(Bureaucrat const &office_rat);
	virtual void		execute(Bureaucrat const &executor) const = 0;
	

	// they are virtual because std::exception what in the base is virtual, so it is a reminder of that
	
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm const& b);

#endif