#include "EuropeanDigitalCallOption.h"

EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike)
{
    // Validation is done in parent class constructor
}

OptionType EuropeanDigitalCallOption::GetOptionType() { return OptionType::Call; }

double EuropeanDigitalCallOption::getPayoff(double spot) const
{
    return (spot >= getStrike()) ? 1.0 : 0.0; // Digital call payoff: h(z) = 1 if z >= K, 0 otherwise
    // Ternary operator: if spot >= strike, return 1.0; otherwise return 0.0
}

EuropeanDigitalCallOption::~EuropeanDigitalCallOption() { }