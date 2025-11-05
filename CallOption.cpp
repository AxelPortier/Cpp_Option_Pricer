#include "CallOption.h"
#include <algorithm>

CallOption::CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}
CallOption::~CallOption() {}

double CallOption::payoff(double spot) const {return std::max(spot-getStrike(), 0.0);}// Payoff function for call option : max(z - K, 0)

OptionType CallOption::getOptionType() const {return OptionType::Call;} // Return option type as call
