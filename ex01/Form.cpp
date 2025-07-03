#include "Form.hpp"

Form::Form(void) : _name("Deafult"), _signed(false), _sign_grade(50), _execute_grade(40){
    std::cout << "Form class default constructor called" << std::endl;
    return;
}

Form::Form(std::string &name, const int &sign_grade, const int &execute_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    std::cout << "Form class full constructor called" << std::endl;
    return;
}

Form::Form(Form const &base) {
    std::cout <<"Form class copy constructor called" << std::endl;
    if (this != base)
    {
        const int
    }
    return (*this);
}

Form::&operator=(Form const &other) {
    std::cout << "Form assignment operator called" << std::endl;
}

Form::~Form(void) {
    std::cout << "Form class destructor called" << std::endl;
    return;
}

bool        Form::getSigned(void) const {
    return  this->_signed;
}

const int&  Form::getSignGrade(void) const {
    return  this->_sign_grade;
}

const int&   Form::getExecuteGrade(void) const {
    return  this->_execute_grade;
}

void         Form::beSigned(Bureaucrat& office_rat) {
    //prints something and changes the status 
}