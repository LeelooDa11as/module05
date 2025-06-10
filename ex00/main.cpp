/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:25:29 by kkoval            #+#    #+#             */
/*   Updated: 2025/06/10 17:25:31 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void ) 
{
	try {
		Bureaucrat b("Alice", 0);  // Will throw GradeTooHighException
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
    	std::cerr << "Caught high exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
    	std::cerr << "Caught low exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
    	std::cerr << "Caught generic exception: " << e.what() << std::endl;
	}
	return 0;
}