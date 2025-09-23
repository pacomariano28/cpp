#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include <exception>

class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw() {
			return "Grade is too high!";
		}
};

#endif