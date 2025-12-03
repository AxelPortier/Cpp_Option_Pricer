#include "AmericanOption.h"
#include <vector>
#include <stdexcept>

// American option constructor: sets expiry and checks strike > 0
AmericanOption::AmericanOption(double expiry,double strike)
    : Option(expiry){
    if(strike<=0){
        throw std::invalid_argument("Strike has to be positive");
    } else {
        _strike = strike;
    }
}

// Destructor
AmericanOption::~AmericanOption(){}

// Return strike price
double AmericanOption::getStrike() const {return _strike;}

// Identify this option as American
bool AmericanOption::isAmericanOption() const {return true;}
