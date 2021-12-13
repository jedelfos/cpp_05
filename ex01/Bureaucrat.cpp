#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( void ) {}

Bureaucrat::Bureaucrat( const std::string& name, unsigned int grade ) :
	_name(name)
{
	set_grade(grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat& obj ) {
	*this = obj;
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if(this == &rhs) { return *this; }

	_name = rhs.get_name();
	_grade = rhs.get_grade();
	return *this;
}

Bureaucrat&	Bureaucrat::operator++( void ) {
	set_grade(get_grade() - 1);
	return *this;
}

Bureaucrat&	Bureaucrat::operator--( void ) {
	set_grade(get_grade() + 1);
	return *this;
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& rhs ) {
	os << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
	return os;
}

void	Bureaucrat::signForm( Form& obj ) const {
	obj.beSigned(*this);
}

const std::string&	Bureaucrat::get_name( void ) const {
	return _name;
}

int	Bureaucrat::get_grade( void ) const {
	return _grade;
}

Bureaucrat&	Bureaucrat::set_name( const std::string& name ) {
	_name = name;
	return *this;
}

Bureaucrat&	Bureaucrat::set_grade( int grade ) {
	try
	{
		if ( 1 > grade)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw () {
	return "Bureaucrat grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw () {
	return "Bureaucrat grade is too low";
}
