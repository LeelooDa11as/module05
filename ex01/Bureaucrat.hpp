/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kate <kate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:18 by kkoval            #+#    #+#             */
/*   Updated: 2025/08/31 22:38:04 by kate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Form;
class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;

	public:
	Bureaucrat( void );
	Bureaucrat( std::string _name, int grade );
	Bureaucrat( Bureaucrat const &copy );
	Bureaucrat &operator=( Bureaucrat const &other );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		increment( int points );
	void		decrement( int points );
	void		signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif