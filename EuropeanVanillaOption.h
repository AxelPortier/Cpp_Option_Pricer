#pragma once
#include "Option.h"
#include <stdexcept>

// Abstract base class for European Call and Put options
class EuropeanVanillaOption : public Option {
private:
    double _strike;

public:
    // Constructor: Initializes expiry and strike
    EuropeanVanillaOption(double, double);
    ~EuropeanVanillaOption();
    double getStrike() const override; // Getter for the strike price K

    virtual double payoff(double) const = 0;
    virtual OptionType getOptionType() const = 0;

    friend class BlackScholesPricer; // Allows BlackScholesPricer to access private members (specifically _strike) for the analytic formula calculation.
};
