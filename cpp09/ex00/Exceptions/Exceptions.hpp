#pragma once

#include <string>

#define ERROR_DB_NOT_OPEN  		"Error: not possible to open the DB file"
#define ERROR_BAD_FORMAT  		"Error: bad format in database line: "
#define ERROR_BAD_INPUT  		"Error: bad input => "
#define ERROR_NOT_POSITIVE  	"Error: not a positive number in line: "
#define ERROR_TOO_LARGE  		"Error: too large a number."
#define ERROR_COULD_NOT_OPEN  	"Error: could not open file."

class BTCExpections {
	public:
		virtual const char* what() const  = 0;
};

class IN_NotOpen : public BTCExpections {
	public:
		virtual const char* what() const {
			return ERROR_COULD_NOT_OPEN;
		}
};

class DB_NotOpen : public BTCExpections {
	public:
		virtual const char* what() const {
			return ERROR_DB_NOT_OPEN;
		}
};

class DB_NoSeparatorFound : public BTCExpections {
	private:
		const std::string _msg;

	public:
		DB_NoSeparatorFound(const std::string& line);
		virtual const char* what() const {
			return _msg.c_str();
		}
};

class DB_BadInput : public BTCExpections {
	private:
		const std::string _msg;

	public:
		DB_BadInput(const std::string& line);
		virtual const char* what() const {
			return _msg.c_str();
		}
};

class DB_NotPositiveNumber : public BTCExpections {
	private:
		const std::string _msg;

	public:
		DB_NotPositiveNumber(const std::string& line);
		virtual const char* what() const {
			return _msg.c_str();
		}
};