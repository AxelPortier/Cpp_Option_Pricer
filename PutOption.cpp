#include "PutOption.h"

PutOption::PutOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike)
{}

double PutOption::payoff(double spot) const {
    double K = getStrike();
    if (spot > K){
        return 0.0;
    }
    else {
        return K-spot;
    }
} // Payoff function for put option : max(K - z, 0)

OptionType PutOption::GetOptionType() const {return OptionType::Put;}
PutOption::~PutOption(){}