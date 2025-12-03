#include "EuropeanDigitalPutOption.h"

EuropeanDigitalPutOption::EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}
EuropeanDigitalPutOption::~EuropeanDigitalPutOption() {}

OptionType EuropeanDigitalPutOption::getOptionType() const {return OptionType::Put;}

// Digital put payoff: h(z) = 1 if z <= K, 0 otherwise
double EuropeanDigitalPutOption::payoff(double spot) const {return spot <= getStrike() ? 1.0 : 0.0;} // Ternary operator: if spot <= strike, return 1.0; otherwise return 0.0