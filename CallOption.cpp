#include "CallOption.h"

CallOption::CallOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike)
{}

double CallOption::payoff(double spot) const { 
    double K = getStrike();
    if (spot < K){
        return 0.0;
    }
    else {
        return spot-K;
    }
} // Payoff function for call option : max(z - K, 0)

EuropeanVanillaOption::optionType CallOption::GetOptionType() const {
    return EuropeanVanillaOption::optionType::Call;
} // Return option type as call
