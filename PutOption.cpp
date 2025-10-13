#include "PutOption.h"

PutOption::PutOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike)
{}

double PutOption::payoff(double z) const {
    double K = getStrike();
    return (K >= z) ? (K - z) : 0.0;
} // Payoff function for put option : max(K - z, 0)

EuropeanVanillaOption::optionType PutOption::GetOptionType() const {
    return optionType::put;
} // Return option type as put
