#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		const int			_grade;
		bool				_signed;

		Form( void );

	public:

		Form( const std::string& name, int grade, bool is_signed = 0 );
		Form( const Form& obj );
		~Form();

		Form&				operator=( const Form& rhs );

		void				beSigned( const Bureaucrat& obj );

		Form&				set_signed( bool boolean );
		const std::string&	get_name( void ) const;
		int					get_grade( void ) const;
		bool				is_signed( void ) const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw ();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw ();
		};
};

std::ostream&		operator<<( std::ostream& os, const Form& rhs );

#endif
