#pragma once
#include "EuropeanDigitalOption.h"

// Class representing a European Digital Call Option (also known as a Binary Call)
class EuropeanDigitalCallOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalCallOption(double, double); // Constructor taking expiry and strike price
    ~EuropeanDigitalCallOption();

    OptionType getOptionType() const override; // Returns the type of the option (Call)
    double payoff(double spot) const override; // useful to override payoff function
};