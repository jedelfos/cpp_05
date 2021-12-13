#include "Bureaucrat.hpp"

int main () {

	Bureaucrat	obj("name", 3);

	std::cout << "------------------------" << std::endl;

	std::cout << obj << std::endl;
	++obj;
	std::cout << obj << std::endl;
	++obj;
	std::cout << obj << std::endl;
	++obj;
	std::cout << obj << std::endl;

	std::cout << "------------------------" << std::endl;

	std::cout << obj << std::endl;
	--obj;
	std::cout << obj << std::endl;
	--obj;
	std::cout << obj << std::endl;
	--obj;
	std::cout << obj << std::endl;

	std::cout << "------------------------" << std::endl;

	++obj;
	++obj;
	++obj;
	++obj;
	++obj;
	++obj;
	++obj;
	++obj;
	++obj;

	std::cout << "------------------------" << std::endl;

	return (0);
}