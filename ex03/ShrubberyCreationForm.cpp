#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery", 145, 137), _target("No target") {
    std::cout << "ShrubberyCreationForm default class constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137) {
    this->_target = target;
    std::cout << "ShrubberyCreationForm target class constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
    std::cout << "ShrubberyCreationForm copy class constructor called" << std::endl;
    this->_target = other._target;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { 
    std::cout << "ShrubberyCreationForm class destructor called" << std::endl;
}

const std::string&	ShrubberyCreationForm::getTarget(void) const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    exec_prep(executor);

    std::string		file_name = getTarget() + "_shrubbery";
    std::ofstream	file(file_name.c_str());

    if (!file.is_open()) {
        std::cerr << file_name << " could not be opened" << std::endl;
        return;
    }
	file << "       _-_       \n"
            "    /~~   ~~\\   \n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~  \n"
            "_- -   | | _- _ \n"
            "  _ -  | |   -_ \n"
            "      // \\\\     \n";

	file.close(); // optional here, the end of scope would close it, but would be necessary if another file would be opened in the same function
}
