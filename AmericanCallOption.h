#pragma once
#include "AmericanOption.h"
#include <vector>

// American call option, derived from AmericanOption
class AmericanCallOption: public AmericanOption{
public:
    // Constructor: expiry, strike
    AmericanCallOption(double,double);
    
    // Destructor
    ~AmericanCallOption();
    
    // Returns Call as option type
    OptionType getOptionType() const override;
    
    // Payoff for a given spot price
    double payoff(double) const override;
};
