#pragma once

#include "EuropeanVanillaOption.h"

class PutOption : public EuropeanVanillaOption {
public:
    PutOption(double, double); // Constructor from VanillaOption
    ~PutOption();

    double payoff(double) const override; // Payoff function for put option
    OptionType getOptionType() const override; // Return option type as put
};

