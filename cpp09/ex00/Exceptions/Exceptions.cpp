
#include "Exceptions.hpp"
#include <string>

DB_BadInput::DB_BadInput(const std::string& line)					: _msg(std::string(ERROR_BAD_INPUT) + line) {}
DB_NoSeparatorFound::DB_NoSeparatorFound(const std::string& line) 	: _msg(std::string(ERROR_BAD_FORMAT) + line) {}
DB_NotPositiveNumber::DB_NotPositiveNumber(const std::string& line) : _msg(std::string(ERROR_NOT_POSITIVE) + line) {}