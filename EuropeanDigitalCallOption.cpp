#include "EuropeanDigitalCallOption.h"
#include <stdexcept>

EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike)
{
    // Validation is done in parent class constructor
}


double EuropeanDigitalCallOption::getPayoff(double spot) const
{
    return (spot >= _strike) ? 1.0 : 0.0; // Digital call payoff: h(z) = 1 if z >= K, 0 otherwise
}