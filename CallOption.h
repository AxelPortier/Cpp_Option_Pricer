#pragma once    

#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption {
public:
    CallOption(double, double); // Constructor from VanillaOption
    ~CallOption();

    double payoff(double) const override; // Payoff function for call option
    OptionType getOptionType() const override; // Override and Return option type
};

