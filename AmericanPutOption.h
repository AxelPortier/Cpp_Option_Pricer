#pragma once
#include "AmericanOption.h"
#include <vector>

// American put option class, derived from AmericanOption
class AmericanPutOption: public AmericanOption{
public:
    // Constructor: expiry, strike
    AmericanPutOption(double,double);
    // Destructor
    ~AmericanPutOption();
    
    // Returns Put as option type
    OptionType getOptionType() const override;
    // Payoff for a given spot price
    double payoff(double) const override;
};
