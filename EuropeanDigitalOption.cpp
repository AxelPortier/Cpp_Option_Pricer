#include "EuropeanDigitalOption.h"
#include <stdexcept>

EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike)
{
    if (expiry < 0 || strike < 0)
        throw std::invalid_argument("Expiry and strike must be nonnegative");
}
EuropeanDigitalOption::~EuropeanDigitalOption() {}

// Overriden
bool EuropeanDigitalOption::isDigital() const {return true;}
double EuropeanDigitalOption::getStrike() const {return _strike;}

