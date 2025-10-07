#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#define RESET	"\033[0m"
#define BLUE	"\033[38;5;117m"

void    test_intern(void) {
    std::cout << BLUE << "-------------------- Intern Testing --------------------\n" << RESET << std::endl;
    Intern      poorIntern;
    Bureaucrat  boss("Mr Boss", 1);

    try {
        AForm* f1 = poorIntern.makeForm("Shrubbery", "Alice");
        AForm* f2 = poorIntern.makeForm("RobotomyRequest", "Bob");
        AForm* f3 = poorIntern.makeForm("PresidentialPardon", "Garden");

        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;

        boss.signForm(*f1);
        boss.signForm(*f2);
        boss.signForm(*f3);

        boss.executeForm(*f1);
        boss.executeForm(*f2);
        boss.executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test invalid form
    try {
        AForm* invalid = poorIntern.makeForm("not a form", "Nobody");
		std::cerr << "!!! If you see it I am in trouble !!!" << std::endl;
        delete invalid;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main(void) {
    test_intern();
   return(1);
}