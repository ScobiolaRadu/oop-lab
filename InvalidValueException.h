#ifndef _INVALIDVALUEEXCEPTION_H_
#define _INVALIDVALUEEXCEPTION_H_
#include <memory>

class InvalidValueException : public std::exception
{
public:
    InvalidValueException() = default;
    const char *what() const noexcept override;
};

#endif // _INVALIDVALUEEXCEPTION_H_