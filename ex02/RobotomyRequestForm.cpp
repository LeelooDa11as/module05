#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::seeded = false;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("No target") {
    std::cout << "RobotomyRequestForm default class constructor called" << std::endl;
    bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "RobotomyRequestForm target class constructor called" << std::endl;
    this->_target = target;
     if (!seeded) {
        srand(time(0));
        seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other) : AForm(other) {
    std::cout << "RobotomyRequestForm copy class constructor called" << std::endl;
    this->_target = other._target;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { 
    std::cout << "RobotomyRequestForm class destructor called" << std::endl;
}

const std::string&	RobotomyRequestForm::getTarget(void) const {
    return this->_target;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    exec_prep(executor);

	if (rand() % 2){
        std::cout << "BrRR bRrbr .............. BRZZZZbRrrrrrr" << std::endl;
        std::cout << getTarget() << "  has been robotomized successfully" << std::endl;
    }
    else
        std::cout << "Sorry, robotomy failed" << std::endl;
}