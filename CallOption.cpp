#include "CallOption.h"

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}
CallOption::~CallOption() {}

// Payoff function for call option : max(z - K, 0)
double CallOption::payoff(double spot) const { 
    double K = getStrike();
    if (spot < K){
        return 0.0;
    }
    else {
        return spot-K;
    }
}

OptionType CallOption::getOptionType() const {return OptionType::Call;} // Return option type as call
