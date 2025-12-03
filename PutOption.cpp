#include "PutOption.h"
#include <algorithm>

PutOption::PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {} // Uses the constructor of EuropeanVanillaOption
PutOption::~PutOption(){}

double PutOption::payoff(double spot) const {return std::max(getStrike()-spot , 0.0);} // Payoff function for put option : max(K - z, 0)

OptionType PutOption::getOptionType() const {return OptionType::Put;} // Return option type as call
