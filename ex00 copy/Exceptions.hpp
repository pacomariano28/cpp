#pragma once

#include <string>
#include <exception>

#define ERROR_DB_NOT_OPEN  		"Error: not possible to open the DB file"
#define ERROR_BAD_FORMAT  		"Error: bad format in database line: "
#define ERROR_BAD_INPUT  		"Error: bad input => "
#define ERROR_NOT_POSITIVE  	"Error: not a positive number => "
#define ERROR_TOO_LARGE  		"Error: too large a number => "
#define ERROR_COULD_NOT_OPEN  	"Error: could not open file."

class BTCExpections : std::exception {
	public:
		virtual const char* what() const throw()  = 0;
};

// DATABASE EXCEPTIONS /////////////////////////////////////////////////

class DB_NotOpen : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_DB_NOT_OPEN;
		}
};


// INPUT EXCEPTIONS /////////////////////////////////////////////////

class IN_NotOpen : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_COULD_NOT_OPEN;
		}
};

class IN_BadDate : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_BAD_INPUT;
		}
};

class IN_EmptyValue : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_BAD_INPUT;
		}
};

class IN_NotPositiveNumber : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_NOT_POSITIVE;
		}
};

class IN_NotNumericValue : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_BAD_INPUT;
		}
};

class IN_OutOfRange : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_TOO_LARGE;
		}
};

class IN_NoSeparator : public BTCExpections {
	public:
		virtual const char* what() const throw() {
			return ERROR_BAD_INPUT;
		}
};
