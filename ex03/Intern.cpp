#include "Intern.hpp"

Intern::Intern() {
	_f[0] = &Intern::Smake;
	_f[1] = &Intern::Rmake;
	_f[2] = &Intern::Pmake;
}

Intern::~Intern() {

}

Intern::Intern( const Intern& obj) {
	*this = obj;
}

Intern&			Intern::operator=( const Intern& rhs ) {
	if (this == &rhs)
		return *this;

	_f[0] = rhs._f[0];
	_f[1] = rhs._f[1];
	_f[2] = rhs._f[2];
	return *this;
}

Form*	Intern::makeForm( const std::string& name, const std::string& target ) {
	for (int i = 0; i < 3; i++) {
		Form*	tmp = (this->*_f[i])(target);

		if (name == tmp->get_name()) { return tmp; }

		delete tmp;
	}
	return 0;
}

Form*	Intern::Smake( const std::string& target ) {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::Rmake( const std::string& target ) {
	return new RobotomyRequestForm(target);
}

Form*	Intern::Pmake( const std::string& target ) {
	return new PresidentialPardonForm(target);
}
