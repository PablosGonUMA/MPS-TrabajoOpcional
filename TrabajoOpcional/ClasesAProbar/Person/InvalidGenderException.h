#ifndef INVALIDGENDEREXCEPTION_H
#define INVALIDGENDEREXCEPTION_H

#include <stdexcept>
#include <string>
class InvalidGenderException : public std::runtime_error {
public:
	InvalidGenderException(const std::string& errorMessage);
};
#endif
