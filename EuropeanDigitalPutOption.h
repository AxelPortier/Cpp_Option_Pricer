#pragma once
#include "EuropeanDigitalOption.h"

// Class representing a European Digital Put Option.
class EuropeanDigitalPutOption : public EuropeanDigitalOption
{
public:
    EuropeanDigitalPutOption(double, double); // Constructor taking expiry and strike price
    ~EuropeanDigitalPutOption();

    OptionType getOptionType() const override; // Returns the type of the option (Put)
    double payoff(double) const override; // Override the payoff function to implement the digital behavior
};