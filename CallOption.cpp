#include "CallOption.h"

CallOption::CallOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike)
{}

double CallOption::payoff(double z) const { 
    double K = getStrike();
    return (z >= K) ? (z - K) : 0.0;
} // Payoff function for call option : max(z - K, 0)

EuropeanVanillaOption::optionType CallOption::GetOptionType() const {
    return optionType::call;
} // Return option type as call
