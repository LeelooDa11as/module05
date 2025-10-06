/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kate <kate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:26:42 by kkoval            #+#    #+#             */
/*   Updated: 2025/09/19 03:53:07 by kate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;
class	Form {
	private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_execute_grade;

	public:
	
	Form(void);
	Form(const std::string &name, const int &sign_grade, const int &execute_grade);
	Form(Form const &base);
	Form &operator=(Form const &other);
	~Form(void);
	
	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	const int&			getSignGrade(void) const;
	const int&			getExecuteGrade(void) const;

	void				beSigned(const Bureaucrat &office_rat);
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form const& b);

#endif