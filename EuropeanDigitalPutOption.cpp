#include "EuropeanDigitalPutOption.h"


EuropeanDigitalPutOption::EuropeanDigitalPutOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike)
{
    // Validation is done in parent class constructor
}

double EuropeanDigitalPutOption::getPayoff(double spot) const
{
    return (spot <= _strike) ? 1.0 : 0.0; // Digital put payoff: h(z) = 1 if z <= K, 0 otherwise
}