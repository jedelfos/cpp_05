#include "Form.hpp"

Form::Form( void ) : _name("unnamed"), _grade(150), _signed(false) {}

Form::~Form( void ) {}

Form::Form( const std::string& name, int grade , bool is_signed )
	: _name(name), _grade(grade), _signed(is_signed) {
	if (grade < 1)
		throw (Form::GradeTooHighException());
	else if (grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form( const Form& obj ) : _name(obj.get_name()), _grade(obj.get_grade()) { *this = obj; }

Form&				Form::operator=( const Form& rhs ) {
	if (this == &rhs)
		return *this;

	_signed = rhs.is_signed();
	return *this;
}

std::ostream&		operator<<( std::ostream& os, const Form& rhs ) {
	os << rhs.get_name() << ", needs " << rhs.get_grade() << " grade to be signed.";
	if (rhs.is_signed())
		os << " Its signed.";
	else
		os << " Its not signed.";
	return os;
}

void				Form::beSigned( const Bureaucrat& obj ) {
	if (is_signed()) {
		throw Form::FormAlreadySignedException();
	}
	else if (get_grade() < obj.get_grade()) {
		throw Form::BureaucratGradeTooLowException();
	}
	else {
		set_signed(true);
	}
}

Form&				Form::set_signed( bool boolean ) {
	_signed = boolean;

	return *this;
}

const std::string&	Form::get_name( void ) const { return _name; }
int					Form::get_grade( void ) const { return _grade; }
bool				Form::is_signed( void ) const { return _signed; }

const char*			Form::GradeTooHighException::what() const throw() {
	return "Form grade too high, invalid Form";
}

const char*			Form::GradeTooLowException::what() const throw() {
	return "Form grade too low, invalid Form";
}

const char*			Form::FormAlreadySignedException::what() const throw() {
	return "Form already signed";
}

const char*			Form::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

const char*			Form::BureaucratGradeTooLowException::what( void ) const throw () {
	return "Bureaucrat grade to low";
}
