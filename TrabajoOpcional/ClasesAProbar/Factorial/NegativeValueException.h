#ifndef NEGATIVEVALUEEXCEPTION_H
#define NEGATIVEVALUEEXCEPTION_H

#include <stdexcept>
#include <string>

class NegativeValueException : public std::runtime_error {
public:
    explicit NegativeValueException(const std::string& errorMessage);
};

#endif
