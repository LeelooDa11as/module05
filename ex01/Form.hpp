/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:26:42 by kkoval            #+#    #+#             */
/*   Updated: 2025/08/27 16:59:17 by kkoval           ###   ########.fr       */
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
	Form(std::string &name, const int &sign_grade, const int &execute_grade);
	Form(Form const &base);
	Form &operator=(Form const &other);
	~Form(void);
	
	bool				getSigned(void) const;
	const int&			getSignGrade(void) const;
	const int&			getExecuteGrade(void) const;

	void				beSigned(Bureaucrat &office_rat); // makes the form signed if the bureaucrat's grade is high enough
	
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form const& b);

#endif