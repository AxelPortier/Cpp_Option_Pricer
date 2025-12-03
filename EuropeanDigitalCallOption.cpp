#include "EuropeanDigitalCallOption.h"

EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {} // Constructor: Initializes the base EuropeanDigitalOption with expiry and strike
EuropeanDigitalCallOption::~EuropeanDigitalCallOption() {}

OptionType EuropeanDigitalCallOption::getOptionType() const {return OptionType::Call;} // Helper method to return the OptionType enum

// Digital call payoff: h(z) = 1 if z >= K, 0 otherwise
double EuropeanDigitalCallOption::payoff(double spot) const{return spot >= getStrike() ? 1.0 : 0.0;} // Ternary operator: if spot >= strike, return 1.0; otherwise return 0.0