#ifndef CALLOPTION_H
#define CALLOPTION_H

#include "EuropeanVanillaOption.h"

class CallOption : public EuropeanVanillaOption {
public:
    CallOption(double expiry, double strike); // Constructor from VanillaOption

    virtual double payoff(double z) const override; // Payoff function for call option
    virtual optionType GetOptionType() const override; // Return option type
};

#endif
