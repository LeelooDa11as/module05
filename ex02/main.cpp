#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET	"\033[0m"
#define BLUE	"\033[38;5;117m"

void    test1(void) {
    std::cout << BLUE << "--------------------Pollymophy and variables--------------------\n" << RESET << std::endl;
    PresidentialPardonForm  form1("Nancy");
    ShrubberyCreationForm   form2("Rose");
    AForm                   *form3 = new RobotomyRequestForm("Jenny");
    
    std::cout << "FORM1 info getters" << std::endl;
    std::cout << form1.getName() << std::endl;
    std::cout << form1.getTarget() << std::endl;
    if (form1.getSigned())
        std::cout << "Signed" << std::endl;
    if (!form1.getSigned())
        std::cout << "Not signed" << std::endl;
    std::cout << "Signed grade is " << form1.getSignGrade() << std::endl;
    std::cout << "Execute grade is " << form1.getExecuteGrade() << std::endl;
    std::cout << std::endl;

    std::cout << "FORM2 std::cout with Magic of pollymorphy brili-brili" << std::endl;
    std::cout << form2 << std::endl;
    std::cout << std::endl;

    std::cout << "FORM3" << std::endl;
    std::cout << *form3 << std::endl;
    std::cout << std::endl;


    Bureaucrat  Pepe("Pepe", 2);
    Pepe.signForm(form1);
    Pepe.signForm(form2);
    Pepe.signForm(*form3);
    
    Pepe.executeForm(form1);
    Pepe.executeForm(form2);
    Pepe.executeForm((*form3));
    delete(form3);
    return;
}

void    test2(void) {
    std::cout << BLUE << "--------------------Exception Testing--------------------\n" << RESET << std::endl;

    PresidentialPardonForm  form1("Nancy");
    ShrubberyCreationForm   form2("Rose");
    RobotomyRequestForm     form3("Jenny");

    Bureaucrat              junior("Bob", 150);
    Bureaucrat              mid("Peter", 70);
    Bureaucrat              senior("Mr Big", 20);

	senior.executeForm(form1);
	junior.signForm(form1);
	senior.signForm(form1);
	std::cout << form1 << std::endl;
	senior.executeForm(form1);
	try {
		senior.increment(15);
		std::cerr << "!!! If you see this exception failed !!!" << std::endl;
	}
	catch(const std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	senior.executeForm(form1);

	try {
		junior.increment(150);
		std::cerr << "!!! If you see this exception failed !!!" << std::endl;
	}
	
	catch(const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	mid.signForm(form2);
	mid.increment(25);
	mid.signForm(form2);
	mid.executeForm(form2);
	junior.increment(30);
	junior.signForm(form2);
	junior.executeForm(form2);

	std::cout << "\nLet's see who has luck with Robotomized\n" << std::endl;

	senior.signForm(form3);
	std::cout << "!!!!!" << std::endl;
	senior.executeForm(form3);
	mid.executeForm(form3);
	senior.executeForm(form3);

    return;
}

int main() {
    //test1();
    test2();
    //test3();
    
   return(1);
}