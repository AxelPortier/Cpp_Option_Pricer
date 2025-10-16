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
        return spot-K;
    }
} // Payoff function for put option : max(K - z, 0)

EuropeanVanillaOption::optionType PutOption::GetOptionType() const {
    return EuropeanVanillaOption::optionType::Put;
}
