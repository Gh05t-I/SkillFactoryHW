#pragma once
#include <exception>

class BadRange : public std::exception {
public:
    const char* what() const noexcept override;
};