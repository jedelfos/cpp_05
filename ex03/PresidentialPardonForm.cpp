#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _execGrade(5), _target("") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& rhs )
	: Form(rhs.get_name(), rhs.get_grade(), false), _execGrade(5), _target(rhs.get_target()) {
	*this = rhs;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: Form("PresidentialPardonForm", 25, false), _execGrade(5), _target(target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& obj ) {
	if (this == &obj)
		return *this;

	set_signed(obj.is_signed());
	_target = obj.get_target();
	return *this;
}

void					PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
	if (is_signed() == false) {
		throw Form::FormNotSignedException();
	}
	else if (get_execGrade() < executor.get_grade()) {
		throw Form::BureaucratGradeTooLowException();
	}
	else {
			std::cout << get_target() << " has been pardoned" << std::endl;
	}
}

int						PresidentialPardonForm::get_execGrade() const { return _execGrade; }

const std::string&		PresidentialPardonForm::get_target() const { return _target; }
void					PresidentialPardonForm::set_target( const std::string& target ) { _target = target; }
