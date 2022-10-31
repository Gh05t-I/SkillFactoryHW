#pragma once
#include <exception>

class BadLenght : public std::exception {
public:
    const char* what() const throw() override;
};