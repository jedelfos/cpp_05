#include "Form.hpp"

Form::Form( void ) : _name("unnamed"), _grade(150), _signed(false) {}

Form::~Form( void ) {}

Form::Form( const std::string& name, int grade , bool is_signed ) : _name(name), _grade(grade), _signed(is_signed) {
	if (grade < 1)
		std::cerr << "Error: Form grade too high" << std::endl;
	else if (grade > 150)
		std::cerr << "Error: Form grade too low" << std::endl;
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
	if (this->is_signed())
	{
		std::cout << obj.get_name() << " cannot sign " <<
				this->get_name() << " because its already signed" << std::endl;
		return;
	}
	try
	{
		if (this->get_grade() < 1) {
			throw Form::GradeTooHighException();
		}
		else if (this->get_grade() > 150) {
			throw Form::GradeTooLowException();
		}
		else {
			if (obj.get_grade() <= this->get_grade()) {
				std::cout << obj.get_name() << " signs " << this->get_name() << std::endl;
				this->set_signed(true);
			} else {
				std::cout << obj.get_name() << " cannot sign " <<
					this->get_name() << " because grade is to low" << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

Form&				Form::set_signed( bool boolean ) {
	_signed = boolean;

	return *this;
}

const std::string&	Form::get_name( void ) const { return _name; }
int					Form::get_grade( void ) const { return _grade; }
bool				Form::is_signed( void ) const { return _signed; }

const char*			Form::GradeTooHighException::what( void ) const throw () {
	return "Form grade too high";
}

const char*			Form::GradeTooLowException::what( void ) const throw () {
	return "Form grade too low";
}
