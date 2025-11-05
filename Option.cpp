#include <iostream>
#include "Option.h"

Option::Option(double exp) : _expiry(exp){};
double Option::getExpiry() const{
    return _expiry;
}

double Option::payoffPath(const std::vector<double>& path) const{
    if (path.empty()) return 0.0;
    return payoff(path.back());
}

bool Option::isDigital(){
    return false;
}
bool Option::isAsianOption(){
    return false; 
}
bool Option::isAmericanOption(){
    return false; 
}