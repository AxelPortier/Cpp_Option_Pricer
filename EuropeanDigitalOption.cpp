#include "EuropeanDigitalOption.h"
#include <stdexcept>

// Constructor for the abstract base class of Digital Options.
EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) 
{
    if (expiry < 0 || strike < 0) // Validation: Ensure arguments are non-negative as required by the specifications
        throw std::invalid_argument("Expiry and strike must be nonnegative");
}
EuropeanDigitalOption::~EuropeanDigitalOption() {}

// Overriden
bool EuropeanDigitalOption::isDigital() const {return true;}
double EuropeanDigitalOption::getStrike() const {return _strike;} // Getter for the strike price K.

