#pragma once

#include <iostream>
#include<exception>


class BadLenght : std::exception {

public:
    virtual const char* what() const noexcept {
        return "invalid lenght";
    }
};

class BadRange : std::exception {
public:
    virtual const char* what() const noexcept {
        return "the argument exceeds the size of the array";
    }
};