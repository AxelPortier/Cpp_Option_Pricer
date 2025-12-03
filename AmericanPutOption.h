#pragma once
#include "AmericanOption.h"
#include <vector>

class AmericanPutOption: public AmericanOption{
public:
    AmericanPutOption(double,double);
    ~AmericanPutOption();
    
    OptionType getOptionType() const override;
    double payoff(double) const override;
};