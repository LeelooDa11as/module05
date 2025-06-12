/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:26:42 by kkoval            #+#    #+#             */
/*   Updated: 2025/06/12 19:50:54 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than filling out a stack of forms?
Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class	Form {
	private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_for_sign;
	const int			_grade_for_execute;

	public:
	void	beSigned(Bureaucrat& );
	void	 
};

std::ostream& operator<<(std::ostream& os, Form const& b);

#endif
