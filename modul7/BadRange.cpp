#include "BadRange.h"

const char* BadRange::what() const noexcept{
    return "the argument exceeds the size of the array";
}