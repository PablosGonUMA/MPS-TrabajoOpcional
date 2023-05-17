#ifndef INVALIDAGEEXCEPTION_H
#define INVALIDAGEEXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidAgeException : public std::runtime_error {
public:
	explicit InvalidAgeException(const std::string& errorMessage);
};

#endif