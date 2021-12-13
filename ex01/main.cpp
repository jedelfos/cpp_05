#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

	Bureaucrat	user("bob", 1);
	Bureaucrat	bad_user("Bad bob", -1);
	Form		form("Paper", 4);
	Form		bad_form("Bad paper", -10);


	std::cout << "--------------------------------------------------------" << std::endl;

	std::cout << user << std::endl;
	std::cout << bad_user << std::endl;
	std::cout << form << std::endl;
	std::cout << bad_form << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	user.signForm(form);
	user.signForm(form);

	std::cout << "--------------------------------------------------------" << std::endl;

	form.set_signed(false);
	user.set_grade(10);
	user.signForm(form);

	std::cout << "--------------------------------------------------------" << std::endl;

	std::cout << bad_form << std::endl;

	std::cout << "--------------------------------------------------------" << std::endl;

	user.signForm(bad_form);

	return (0);
}
