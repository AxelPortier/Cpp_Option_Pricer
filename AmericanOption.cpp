#include "AmericanOption.h"
#include <vector>
#include <stdexcept>

AmericanOption::AmericanOption(double expiry,double strike):Option(expiry){
    if(strike<=0){
        throw std::invalid_argument("Strike has to be positive");
    }
    else{
        _strike=strike;
    }
}
AmericanOption::~AmericanOption(){}

double AmericanOption::getStrike() const {return _strike;}
bool AmericanOption::isAmericanOption() const {return true;}