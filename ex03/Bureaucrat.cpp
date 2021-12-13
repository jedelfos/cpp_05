#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( void ) {}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) :
	_name(name)
{
	set_grade(grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ) {
	*this = obj;
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat&			Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if(this == &rhs) { return *this; }

	_name = rhs.get_name();
	_grade = rhs.get_grade();
	return *this;
}

Bureaucrat&			Bureaucrat::operator++( void ) {
	set_grade(get_grade() - 1);
	return *this;
}

Bureaucrat&			Bureaucrat::operator--( void ) {
	set_grade(get_grade() + 1);
	return *this;
}

std::ostream&					operator<<( std::ostream& os, const Bureaucrat& rhs ) {
	os << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
	return os;
}

void				Bureaucrat::signForm( Form& obj ) const {
	try {
		obj.beSigned(*this);
		std::cout << get_name() << " signs "<< obj.get_name() << std::endl;
	} catch (std::exception &e) {
		std::cerr << get_name() << " can't sign " << obj.get_name() << " because " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm( const Form& form ) const {
	try {
		form.execute(*this);
		std::cout << get_name() << " executes " << form.get_name() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << get_name() << " can't execute " << form.get_name() << " because " << e.what() << std::endl;
	}
}

const std::string&	Bureaucrat::get_name( void ) const { return _name; }

int					Bureaucrat::get_grade( void ) const { return _grade; }

Bureaucrat&			Bureaucrat::set_name( const std::string& name ) {
	_name = name;
	return *this;
}

Bureaucrat&			Bureaucrat::set_grade( int grade ) {
	if ( 1 > grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw () {
	return "Bureaucrat grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw () {
	return "Bureaucrat grade is too low";
}
