#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _execGrade(45), _target("") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& rhs )
	: Form(rhs.get_name(), rhs.get_grade(), false), _execGrade(45), _target(rhs.get_target()) {
	*this = rhs;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: Form("RobotomyRequestForm", 72, false), _execGrade(45), _target(target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& obj ) {
	if (this == &obj)
		return *this;

	set_signed(obj.is_signed());
	_target = obj.get_target();
	return *this;
}

void					RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
	if (is_signed() == false) {
		throw Form::FormNotSignedException();
	}
	else if (get_execGrade() < executor.get_grade()) {
		throw Form::BureaucratGradeTooLowException();
	}
	else {
		srand(static_cast<unsigned int>(time(0)));
		if ((rand()) % 2) {
			std::cout << "RizZzZzZzZZZZZzzZz " << get_target() << " has been robotomized successfully" << std::endl;
		}
		else {
			std::cout << get_target() << " has failed to robotomize" << std::endl;
		}
	}
}

int						RobotomyRequestForm::get_execGrade() const { return _execGrade; }

const std::string&		RobotomyRequestForm::get_target() const { return _target; }
void					RobotomyRequestForm::set_target( const std::string& target ) { _target = target; }
