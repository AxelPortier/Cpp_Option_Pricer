#ifndef PUTOPTION_H
#define PUTOPTION_H

#include "EuropeanVanillaOption.h"

class PutOption : public EuropeanVanillaOption {
public:
    PutOption(double expiry, double strike); // Constructor from VanillaOption

    virtual double payoff(double z) const override; // Payoff function for put option : max(K - z, 0)
    virtual optionType GetOptionType() const override; // Return option type as put
};

#endif
