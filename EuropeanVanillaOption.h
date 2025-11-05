#pragma once
#include "Option.h"
#include <stdexcept>

class EuropeanVanillaOption : public Option {
private:
    double _strike;

public:
    // Method that will be implemented in the cpp
    EuropeanVanillaOption(double, double);
    ~EuropeanVanillaOption();
    double getStrike() const override;

    // Virtual pure methode that won't be override in the .ccp
    virtual double payoff(double) const = 0;
    virtual OptionType GetOptionType() const = 0;

    friend class BlackScholesPricer;
};
