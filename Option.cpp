#include <iostream>
#include "Option.h"

Option::Option(double exp) : _expiry(exp){};
double Option::getExpiry() const{
    return _expiry;
}