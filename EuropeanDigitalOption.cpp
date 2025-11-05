#include "EuropeanDigitalOption.h"
#include <stdexcept>

EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike) : Option(expiry)
{
    if (expiry < 0 || strike < 0){ // validation for nonnegative arguments while initializing because digital options require positive time to expiration and positive strike prices
        throw std::invalid_argument("Expiry and strike must be nonnegative");
    }
    else {
        _strike = strike;
    }
}

EuropeanDigitalOption::~EuropeanDigitalOption() {}
bool EuropeanDigitalOption::isDigital() { return true;}
double EuropeanDigitalOption::getStrike() const {return _strike;}

