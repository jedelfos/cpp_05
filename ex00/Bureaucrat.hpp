#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:

		std::string		_name;
		unsigned int	_grade;

		Bureaucrat( void );

	public:

		Bureaucrat( const std::string& name, unsigned int grade );
		Bureaucrat( const Bureaucrat& obj );
		~Bureaucrat( void );

		Bureaucrat&			operator=( const Bureaucrat& rhs );
		Bureaucrat&			operator++( void );
		Bureaucrat&			operator--( void );


		const std::string&	get_name( void ) const;
		unsigned int		get_grade( void ) const;
		Bureaucrat&			set_name( const std::string& name );
		Bureaucrat&			set_grade( int grade );

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw ();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw ();
		};
};
		std::ostream&		operator<<( std::ostream& os, const Bureaucrat& rhs );

#endif
