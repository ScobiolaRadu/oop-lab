#include "InvalidValueException.h"

const char *InvalidValueException::what() const noexcept
{
    return "Invalid value!";
}