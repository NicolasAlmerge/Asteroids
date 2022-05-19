// Unknown resource class declaration
#pragma once
#include "exception"
#include "string"


class UnknownResource: public std::exception {
    std::string errorMessage;

public:
    UnknownResource(const std::string&);
    virtual const char* what() const noexcept override;
};
