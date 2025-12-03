#pragma once
#include "Option.h"
#include <vector>

// Base class for American options
class AmericanOption : public Option {
private:
    double _strike;          // Strike price
public:
    AmericanOption(double expiry, double strike); // Constructor
    ~AmericanOption();                            // Destructor

    bool isAmericanOption() const override;       // Returns true
    double getStrike() const;                     // Getter for strike

    // Pure virtual methods for derived classes
    virtual double payoff(double) const = 0;
    virtual OptionType getOptionType() const = 0;
};
