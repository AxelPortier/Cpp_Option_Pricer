#pragma once
#include "AmericanOption.h"
#include <vector>

class AmericanCallOption: public AmericanOption{
public:
    AmericanCallOption(double,double);
    ~AmericanCallOption();
    
    OptionType getOptionType() const override;
    double payoff(double) const override;
};