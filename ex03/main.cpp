#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {

	Bureaucrat	bob("bob", 1);
	Intern		random;
	Form*		form;

	form = random.makeForm("PresidentialPardonForm", "criminal");
	std::cout << *form << std::endl;

	bob.signForm(*form);
	bob.executeForm(*form);

	delete form;

	return (0);
}

