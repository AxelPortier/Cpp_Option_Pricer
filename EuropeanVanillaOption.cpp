#include "EuropeanVanillaOption.h"
#include <stdexcept>

EuropeanVanillaOption::EuropeanVanillaOption(double expiry, double strike): Option(expiry), _strike(strike)
{
    if (expiry < 0 || strike < 0) // check for nonnegative arguments while initializing
        throw std::invalid_argument("Arguments must be nonnegative");
}
EuropeanVanillaOption::~EuropeanVanillaOption(){}

double EuropeanVanillaOption::getStrike() const {return _strike;}
