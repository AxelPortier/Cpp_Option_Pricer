#include "EuropeanDigitalOption.h"
#include <stdexcept>

EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike)
    : Option(expiry), _strike(strike)
{
    if (expiry < 0 || strike < 0) // validation for nonnegative arguments while initializing because digital options require positive time to expiration and positive strike prices
        throw std::invalid_argument("Expiry and strike must be nonnegative");
}

double EuropeanDigitalOption::getStrike() const {
    return _strike;
}
