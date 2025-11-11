#pragma once
#include "Option.h"
#include <vector>

class AmericanOption : public Option {
private:
	double _strike;
public:
    AmericanOption(double expiry, double maturity); //Constructor that takes the expiry date and monitoring times
    ~AmericanOption(); //Destructor

    bool isAmericanOption() const override;  //return true
    double getStrike() const;

    virtual double payoff(double) const = 0;    
    virtual OptionType getOptionType() const = 0;
};