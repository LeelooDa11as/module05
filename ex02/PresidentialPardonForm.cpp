#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "PresidentialPardonForm default class constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target ) : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "PresidentialPardonForm class constructor called" << std::endl;
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
    std::cout << "PresidentialPardonForm copy class constructor called" << std::endl;
    this->_target = other._target;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { 
    std::cout << "PresidentialPardonForm class destructor called" << std::endl;
}

const std::string&	PresidentialPardonForm::getTarget(void) const {
    return this->_target;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    exec_prep(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}